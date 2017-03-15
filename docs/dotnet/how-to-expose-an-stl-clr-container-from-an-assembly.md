---
title: "Como expor um cont&#234;iner STL/CLR a partir de um assembly | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Contêineres STL/CLR [STL/CLR]"
  - "STL/CLR, problemas entre assemblies"
ms.assetid: 87efb41b-3db3-4498-a2e7-f3ef8a99f04d
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como expor um cont&#234;iner STL/CLR a partir de um assembly
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os contêineres de STL\/CLR como `list` e `map` são implementados como classes de referência do modelo.  Como os modelos C\+\+ são instanciados em tempo de compilação, duas classes de modelo que têm exatamente a mesma assinatura mas são diferentes nos assemblies são realmente tipos diferentes.  Isso significa que as classes de modelo não podem ser usadas nos limites do assembly.  
  
 Para executar o compartilhamento do assembly cruzado possível, implementam dos contêineres de STL\/CLR a interface genérica <xref:System.Collections.Generic.ICollection%601>.  Usando essa interface genérica, todos os idiomas com suporte para os produtos genéricos, inclusive C\+\+, visual C\#, Visual Basic .NET, podem acessar contêiner de STL\/CLR.  
  
 Este tópico mostra como exibir os elementos de vários contêineres de STL\/CLR gravados em c criando `StlClrClassLibrary`nomeado assembly.  Mostrarmos dois assemblies para acessar `StlClrClassLibrary`.  O primeiro assembly é gravado em C\+\+, e o segundo em C\#.  
  
 Se ambos os assemblies são gravados em C\+\+, você pode acessar a interface genérica de um contêiner usando o typedef de `generic_container` .  Por exemplo, se você tiver um contêiner do tipo `cliext::vector<int>`, então a interface genérica é: `cliext::vector<int>::generic_container`.  Da mesma forma, você pode obter um iterador sobre a interface genérica usando o typedef de `generic_iterator` , como em: `cliext::vector<int>::generic_iterator`.  
  
 Como eles typedefs são declarados em arquivos de cabeçalho C\+\+, os assemblies criados em outros idiomas não podem utilizá\-los.  Em virtude disso, para acessar a interface genérica para `cliext::vector<int>` em C\# ou em qualquer outro linguagem .NET, use `System.Collections.Generic.ICollection<int>`.  Para iterar sobre essa coleção, use um loop de `foreach` .  
  
 A tabela a seguir lista a interface genérica que cada contêiner de STL\/CLR implementam:  
  
|Contêiner de STL\/CLR|Interface genérica|  
|---------------------------|------------------------|  
|dequeT\<\>|ICollectionT\<\>|  
|hash\_mapK\<, V\>|IDictionaryK\<, V\>|  
|hash\_multimapK\<, V\>|IDictionaryK\<, V\>|  
|hash\_multisetT\<\>|ICollectionT\<\>|  
|hash\_setT\<\>|ICollectionT\<\>|  
|listT\<\>|ICollectionT\<\>|  
|mapK\<, V\>|IDictionaryK\<, V\>|  
|multimapK\<, V\>|IDictionaryK\<, V\>|  
|multisetT\<\>|ICollectionT\<\>|  
|pavimento\<\>|ICollectionT\<\>|  
|vectorT\<\>|ICollectionT\<\>|  
  
> [!NOTE]
>  Como `queue`, `priority_queue`, e os contêineres de `stack` não oferecem suporte para iteradores, o não implementa as interfaces genéricas e não pode ser acessado assembly cruzado.  
  
## Exemplo 1  
  
### Descrição  
 Neste exemplo, é declaramos a classe c criando que contém dados privados de membro de STL\/CLR.  Nós declaramos em métodos públicos para conceder acesso a coleções particular da classe.  Nós fazemo\-la de duas maneiras diferentes, uma para clientes C\+\+ e uma para outros clientes .NET.  
  
### Código  
  
<CodeContentPlaceHolder>0</CodeContentPlaceHolder>  
## Exemplo 2  
  
### Descrição  
 Neste exemplo, é implementamos a classe declarada no exemplo 1.  Para que os clientes usem essa biblioteca de classe, usamos a ferramenta manifesta **mt.exe** para inserir o arquivo de manifesto na DLL.  Para obter detalhes, consulte os comentários de código.  
  
 Para obter mais informações sobre a ferramenta manifesta os assemblies e lado a lado, consulte [Compilando aplicativos isolados do C\/C\+\+ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md).  
  
### Código  
  
<CodeContentPlaceHolder>1</CodeContentPlaceHolder>  
## Exemplo 3  
  
### Descrição  
 Neste exemplo, criamos o cliente c criando que usa a biblioteca de classes criada nos exemplos 1 e 2.  Esse cliente usa os typedefs de `generic_container` dos contêineres de STL\/CLR para iterar sobre os contêineres e exibir seu conteúdo.  
  
### Código  
  
<CodeContentPlaceHolder>2</CodeContentPlaceHolder>  
### Saída  
  
<CodeContentPlaceHolder>3</CodeContentPlaceHolder>  
## Exemplo 4  
  
### Descrição  
 Neste exemplo, criamos um cliente C\# que usa a biblioteca de classes criada nos exemplos 1 e 2.  Esse cliente usar os métodos de <xref:System.Collections.Generic.ICollection%601> dos contêineres de STL\/CLR para iterar sobre os contêineres e exibir seu conteúdo.  
  
### Código  
  
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
  
### Saída  
  
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
  
## Consulte também  
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)