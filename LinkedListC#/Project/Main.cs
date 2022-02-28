using System;
using Tree;
using List;

class Program
{
    public static void PrintList(List<string> list)
    {
        Console.Write("[");
        list.ForEach((value, index) =>
        {
            Console.Write("\n    {0}: \"{1}\",", index, value);
        });
        Console.Write("\n]\n");
    }
    public static void Main()
    {
        var myTree = new Tree<string>("root");

        var root = myTree.GetRoot();

        root.AddBranch("user");
        root.AddBranch("bin");
        root.AddBranch("etc");

        var branches = root.GetBranches();

        Console.WriteLine("{0}  {1}  {2}", branches[0].GetName(), branches[1].GetName(), branches[2].GetName());
    }
}