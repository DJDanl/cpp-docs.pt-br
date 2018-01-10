---
title: Exportando a partir de uma DLL usando dllexport | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- dllexport
- __declspec
dev_langs: C++
helpviewer_keywords:
- __declspec(dllexport) keyword [C++]
- names [C++], DLL exports by
- export directives [C++]
- exporting DLLs [C++], __declspec(dllexport) keyword
ms.assetid: a35e25e8-7263-4a04-bad4-00b284458679
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 51f20e47724a6d32dad014fbaf025cd283112c54
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exporting-from-a-dll-using-declspecdllexport"></a>Exportando a partir de uma DLL usando __declspec(dllexport)
Microsoft introduzida **__export** na versão de 16 bits de compilador do Visual C++ para permitir que o compilador gerar os nomes de exportação automaticamente e colocá-los em um arquivo. lib. Esse arquivo. lib, em seguida, pode ser usado como um. lib estático para vincular a uma DLL.  
  
 Nas versões mais recentes do compilador, você pode exportar dados, funções, classes ou funções de membro de classe de uma DLL usando o **dllexport** palavra-chave. **dllexport** adiciona a diretiva de exportação para o arquivo de objeto, você não precisa usar um arquivo. def.  
  
 Essa conveniência é mais aparente quando tentar exportar decorado nomes de função do C++. Porque não há nenhuma especificação padrão para a decoração de nome, o nome de uma função exportada pode mudar entre versões do compilador. Se você usar **dllexport**, recompilar os arquivos DLL e .exe dependente é necessário apenas à conta para qualquer alteração de convenção de nomenclatura.  
  
 Várias diretivas de exportação, como números ordinais, NONAME e PRIVADO, podem ser feitas somente em um arquivo. def e não é possível especificar esses atributos sem um arquivo. def. No entanto, usar **dllexport** além de usar um. def arquivo não causa erros de compilação.  
  
 Exportar funções, o **dllexport** palavra-chave deve aparecer à esquerda da palavra-chave a convenção de chamada, se uma palavra-chave for especificada. Por exemplo:  
  
```  
__declspec(dllexport) void __cdecl Function1(void);  
```  
  
 Para exportar todos os membros de dados públicos e funções de membro em uma classe, a palavra-chave deve aparecer à esquerda do nome da classe, da seguinte maneira:  
  
```  
class __declspec(dllexport) CExampleExport : public CObject  
{ ... class definition ... };  
```  
  
> [!NOTE]
>  `__declspec(dllexport)`não pode ser aplicado a uma função com o `__clrcall` convenção de chamada.  
  
 Ao criar a DLL, você normalmente cria um arquivo de cabeçalho que contém os protótipos de função e/ou classes que você está exportando e adicionar **dllexport** às declarações no arquivo de cabeçalho. Para tornar seu código mais legível, definir uma macro para **dllexport** e usar a macro com cada símbolo que você está exportando:  
  
```  
#define DllExport   __declspec( dllexport )   
```  
  
 **dllexport** repositórios função nomes na tabela de exportação da DLL. Se você deseja otimizar o tamanho da tabela, consulte [funções de exportação de uma DLL por Ordinal em vez de por nome](../build/exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md).  
  
> [!NOTE]
>  Ao portar código-fonte DLL de Win16 para Win32, substitua cada ocorrência de **__export** com **dllexport**.  
  
 Como uma referência de pesquisa por meio do arquivo de cabeçalho WinBase Win32. Ele contém exemplos de **__declspec(dllimport)** uso.  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Exportar de uma DLL usando arquivos. def](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Exportar e importar usando AFX_EXT_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)  
  
-   [Exportar funções C++ para uso em executáveis da linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)  
  
-   [Exportar funções C para uso em executáveis C ou linguagem C++](../build/exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)  
  
-   [Determinar qual método de exportação a ser usado](../build/determining-which-exporting-method-to-use.md)  
  
-   [Importar para um aplicativo usando __declspec(dllimport)](../build/importing-into-an-application-using-declspec-dllimport.md)  
  
-   [Inicializar uma DLL](../build/run-time-library-behavior.md#initializing-a-dll)  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [A palavra-chave declspec](../cpp/declspec.md)  
  
-   [Importando e exportando funções embutidas](../build/importing-and-exporting-inline-functions.md)  
  
-   [Importações mútuas](../build/mutual-imports.md)  
  
## <a name="see-also"></a>Consulte também  
 [Exportando de uma DLL](../build/exporting-from-a-dll.md)