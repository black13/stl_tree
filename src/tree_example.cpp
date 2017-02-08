/* 
   This program is free software: you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
*/

#include <algorithm>
#include <string>
#include <iostream>

#include "tree.hpp"
#include "tree_util.hpp"

using namespace std;
using namespace stl_tree;

int main(int argc, char* argv[])
{
   tree<string> tr("root");
   tree<string>::iterator root;

   // build sample tree
   root = tr.begin();
   tree<string>::iterator fruit = tr.insert(root, "fruit");
   tr.append_child(fruit, "apple");
   tr.append_child(fruit, "peach");
   tree<string>::iterator banana = tr.append_child(fruit, "banana");

   tr.append_child(banana, "banana_1");
   tr.append_child(banana, "banana_2");

   stl_tree::print_tree_bracketed(tr);
   cout << endl;

   tree<string>::iterator pos = find(tr.begin(), tr.end(), "banana");
   if (pos != tr.end())
   {
      tree<string>::sibling_iterator sib = tr.begin(pos);
      while (sib != tr.end(pos))
      {
         cout << (*sib) << endl;
         ++sib;
      }
      cout << endl;
      tree<string>::iterator sib2 = tr.begin(pos);
      tree<string>::iterator end2 = tr.end(pos);
      while (sib2 != end2)
      {
         for (int i = 0; i < tr.depth(sib2) - 2; ++i)
            cout << " ";
         cout << (*sib2) << endl;
         ++sib2;
      }
   }

   int count = tr.number_of_children(root);

   return 0;
}
