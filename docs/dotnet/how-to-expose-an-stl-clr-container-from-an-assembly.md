---
title: 'Como: expor um contêiner STL/CLR de um Assembly | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- STL/CLR Containers [STL/CLR]
- STL/CLR, cross-assembly issues
ms.assetid: 87efb41b-3db3-4498-a2e7-f3ef8a99f04d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 58edb96d3947cc5694731d78c6aa71a855ef7aa9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="how-to-expose-an-stlclr-container-from-an-assembly"></a>Como expor um contêiner STL/CLR a partir de um assembly
Contêineres STL/CLR como `list` e `map` são implementados como classes de referência de modelo. Como os modelos do C++ são instanciados no tempo de compilação, duas classes de modelo que tem exatamente a mesma assinatura, mas em diferentes assemblies são realmente diferentes tipos. Isso significa que as classes de modelo não podem ser usados em limites de assembly.  
  
 Para compartilhamento entre os assemblies que possível, contêineres STL/CLR implementam a interface genérica <xref:System.Collections.Generic.ICollection%601>. Usando esta interface genérica, todos os idiomas que oferecem suporte a genéricos, incluindo C++, c# e Visual Basic, podem acessar os contêineres STL/CLR.  
  
 Este tópico mostra como exibir os elementos de vários contêineres STL/CLR gravados em um assembly C++ chamado `StlClrClassLibrary`. Vamos mostrar dois assemblies acessem `StlClrClassLibrary`. O primeiro conjunto é gravado em C++ e o segundo em c#.  
  
 Se os dois assemblies forem escritos em C++, você pode acessar a interface genérica de um contêiner usando seu `generic_container` typedef. Por exemplo, se você tiver um contêiner do tipo `cliext::vector<int>`, é sua interface genérica: `cliext::vector<int>::generic_container`. Da mesma forma, você pode obter um iterador na interface genérica usando o `generic_iterator` typedef, como em: `cliext::vector<int>::generic_iterator`.  
  
 Como essas definições de tipo são declaradas em arquivos de cabeçalho do C++, assemblies escritos em outras linguagens não podem usá-los. Portanto, para acessar a interface genérica para `cliext::vector<int>` em c# ou qualquer outra linguagem .NET, use `System.Collections.Generic.ICollection<int>`. Para iterar sobre essa coleção, use um `foreach` loop.  
  
 A tabela a seguir lista a interface genérica que implementa cada contêiner STL/CLR:  
  
|Contêiner STL/CLR|Interface genérica|  
|------------------------|-----------------------|  
|deque < T\>|ICollection < T\>|  
|hash_map < K, V >|IDictionary < K, V >|  
|hash_multimap < K, V >|IDictionary < K, V >|  
|hash_multiset < T\>|ICollection < T\>|  
|hash_set < T\>|ICollection < T\>|  
|lista < T\>|ICollection < T\>|  
|mapa < K, V >|IDictionary < K, V >|  
|vários mapeamentos < K, V >|IDictionary < K, V >|  
|multiset < T\>|ICollection < T\>|  
|Definir < T\>|ICollection < T\>|  
|Vector < T\>|ICollection < T\>|  
  
> [!NOTE]
>  Porque o `queue`, `priority_queue`, e `stack` contêineres dão suporte a iteradores, eles não implementar interfaces genéricas e não podem ser acessado entre assemblies.  
  
## <a name="example-1"></a>Exemplo 1  
  
### <a name="description"></a>Descrição  
 Neste exemplo, é possível declarar uma classe de C++ que contém dados de membro particular STL/CLR. Em seguida, declaramos métodos públicos para conceder acesso a coleções particulares da classe. Fazemos-la de duas maneiras diferentes, uma para os clientes C++ e outra para outros clientes do .NET.  
  
### <a name="code"></a>Código  
  
<CodeContentPlaceHolder>0</CodeContentPlaceHolder>  
## <a name="example-2"></a>Exemplo 2  
  
### <a name="description"></a>Descrição  
 Neste exemplo, vamos implementar a classe declarada no exemplo 1. Para que os clientes usam essa biblioteca de classe, podemos usar a ferramenta de manifesto **mt.exe** para inserir o arquivo de manifesto na DLL. Para obter detalhes, consulte os comentários de código.  
  
 Para obter mais informações sobre a ferramenta de manifesto e assemblies lado a lado, consulte [compilando aplicativos isolados do C/C++ e Assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md).  
  
### <a name="code"></a>Código  
  
<CodeContentPlaceHolder>1</CodeContentPlaceHolder>  
## <a name="example-3"></a>Exemplo 3:  
  
### <a name="description"></a>Descrição  
 Neste exemplo, podemos criar um cliente de C++ que usa a biblioteca de classes criada nos exemplos 1 e 2. Esse cliente usa o `generic_container` typedefs dos contêineres STL/CLR para iterar sobre os contêineres e exibir seu conteúdo.  
  
### <a name="code"></a>Código  
  
<CodeContentPlaceHolder>2</CodeContentPlaceHolder>  
### <a name="output"></a>Saída  
  
<CodeContentPlaceHolder>3</CodeContentPlaceHolder>  
## <a name="example-4"></a>Exemplo 4  
  
### <a name="description"></a>Descrição  
 Neste exemplo, podemos criar um cliente c# que usa a biblioteca de classes criada nos exemplos 1 e 2. Esse cliente usa o <xref:System.Collections.Generic.ICollection%601> métodos dos contêineres STL/CLR para iterar sobre os contêineres e exibir seu conteúdo.  
  
### <a name="code"></a>Código  
  
```  
// CsConsoleApp.cs  
// compile with: /r:Microsoft.VisualC.STLCLR.dll /r:StlClrClassLibrary.dll /r:System.dll  
  
using System;  
using System.Collections.Generic;  
using StlClrClassLibrary;  
using cliext;  
  
namespace CsConsoleApp  
{  
    class Program  
    {  
        static int Main(string[] args)  
        {  
            StlClrClass theClass = new StlClrClass();  
  
            Console.WriteLine("cliext::deque contents:");  
            ICollection<char> iCollChar = theClass.GetDequeCs();  
            foreach (char c in iCollChar)  
            {  
                Console.WriteLine(c);  
            }  
            Console.WriteLine();  
  
            Console.WriteLine("cliext::list contents:");  
            ICollection<float> iCollFloat = theClass.GetListCs();  
            foreach (float f in iCollFloat)  
            {  
                Console.WriteLine(f);  
            }  
            Console.WriteLine();  
  
            Console.WriteLine("cliext::map contents:");  
            IDictionary<int, string> iDict = theClass.GetMapCs();  
            foreach (KeyValuePair<int, string> kvp in iDict)  
            {  
                Console.WriteLine("{0} {1}", kvp.Key, kvp.Value);  
            }  
            Console.WriteLine();  
  
            Console.WriteLine("cliext::set contents:");  
            ICollection<double> iCollDouble = theClass.GetSetCs();  
            foreach (double d in iCollDouble)  
            {  
                Console.WriteLine(d);  
            }  
            Console.WriteLine();  
  
            Console.WriteLine("cliext::vector contents:");  
            ICollection<int> iCollInt = theClass.GetVectorCs();  
            foreach (int i in iCollInt)  
            {  
                Console.WriteLine(i);  
            }  
            Console.WriteLine();  
  
            return 0;  
        }  
    }  
}  
```  
  
### <a name="output"></a>Saída  
  
```  
cliext::deque contents:  
a  
b  
  
cliext::list contents:  
3.14159  
2.71828  
  
cliext::map contents:  
0 Hello  
1 World  
  
cliext::set contents:  
2.71828  
3.14159  
  
cliext::vector contents:  
10  
20  
```  
  
## <a name="see-also"></a>Consulte também  
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)