---
title: "Exportando a partir de uma DLL usando __declspec(dllexport) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "dllexport"
  - "__declspec"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec(dllexport) [C++]"
  - "diretivas de exportação [C++]"
  - "exportando DLLs [C++], Palavra-chave __declspec(dllexport)"
  - "nomes [C++], Exportações de DLL por"
ms.assetid: a35e25e8-7263-4a04-bad4-00b284458679
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Exportando a partir de uma DLL usando __declspec(dllexport)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A Microsoft introduziu **\_\_export** na versão de 16 bits do compilador do Visual C\+\+ para permitir que ele gere os nomes de exportação automaticamente e os coloque em um arquivo .lib.  Este arquivo .lib pode então ser usado apenas como um .lib estático para vincular a uma DLL.  
  
 Em versões mais recentes do compilador, você pode exportar dados, funções, classes ou funções de membro de classe de uma DLL usando a palavra\-chave **\_\_declspec\(dllexport\)**.  **\_\_declspec\(dllexport\)** adiciona a política de exportação ao arquivo de objeto para que você não precise usar um arquivo .def.  
  
 Esta conveniência é mais aparente quando você tenta exportar nomes de função do C\+\+ decoradas.  Como não há nenhuma especificação padrão para a decoração de nome, o nome de uma função exportada pode alterar entre versões do compilador.  Caso você use **\_\_declspec\(dllexport\)**, a recompilação da DLL e dos arquivos .exe dependentes é necessária apenas para levar em conta todas as alterações na convenção de nomenclatura.  
  
 Muitas diretivas de exportação, como ordinais, NONAME e PRIVATE, podem ser feitas somente em um arquivo de .def, e não há nenhuma maneira de especificar esses atributos sem um arquivo de .def.  No entanto, usar **\_\_declspec\(dllexport\)**, além de um arquivo .def, não causa erros de compilação.  
  
 Para exportar funções, a palavra\-chave **\_\_declspec\(dllexport\)** deve aparecer à esquerda da palavra\-chave chamada de convenção, se uma palavra\-chave for especificada.  Por exemplo:  
  
```  
__declspec(dllexport) void __cdecl Function1(void);  
```  
  
 Para exportar todos os membros de dados e funções de membro públicos em uma classe, a palavra\-chave deverá aparecer à esquerda do nome da classe, como a seguir:  
  
```  
class __declspec(dllexport) CExampleExport : public CObject  
{ ... class definition ... };  
```  
  
> [!NOTE]
>  `__declspec(dllexport)` não pode ser aplicado a uma função com a convenção de chamada `__clrcall`.  
  
 Para compilar a DLL, você normalmente cria um arquivo de cabeçalho que contém os protótipos e\/ou as classes da função que você está exportando e adiciona **\_\_declspec\(dllexport\)** às declarações no arquivo de cabeçalho.  Para tornar seu código mais legível, defina uma macro para **\_\_declspec\(dllexport\)** e use a macro com todos os símbolos que você estiver exportando:  
  
```  
#define DllExport   __declspec( dllexport )   
```  
  
 **\_\_declspec\(dllexport\)** armazena nomes de função na tabela de exportação da DLL.  Se você deseja otimizar o tamanho da tabela, consulte [Exportar funções de uma DLL por ordinal em vez de por nome](../build/exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md).  
  
> [!NOTE]
>  Ao mover o código\-fonte da DLL do Win16 para Win32, substitua todas as instâncias de **\_\_export** por **\_\_declspec\(dllexport\)**.  
  
 Como uma referência, pesquise pelo arquivo de cabeçalho Winbase.h do Win32.  Contém exemplos de uso de **\_\_declspec\(dllimport\)**.  
  
## O que você deseja fazer?  
  
-   [Exportação de uma DLL usando arquivos .def](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Exportar e importar usando AFX\_EXT\_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)  
  
-   [Exportar funções de C\+\+ para uso em executáveis de linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)  
  
-   [Exportar funções de C para uso em executáveis de linguagem C ou C\+\+](../build/exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)  
  
-   [Determine o método de exportação a ser usado](../build/determining-which-exporting-method-to-use.md)  
  
-   [Importar em um aplicativo usando \_\_declspec \(dllimport\)](../build/importing-into-an-application-using-declspec-dllimport.md)  
  
-   [Inicialize um DLL](../build/initializing-a-dll.md)  
  
## Que você deseja saber mais?  
  
-   [A palavra\-chave \_\_declspec](../cpp/declspec.md)  
  
-   [Importando e exportando funções embutidas](../Topic/Importing%20and%20Exporting%20Inline%20Functions.md)  
  
-   [Importações Mútuas](../Topic/Mutual%20Imports.md)  
  
## Consulte também  
 [Exportando a partir de uma DLL](../build/exporting-from-a-dll.md)