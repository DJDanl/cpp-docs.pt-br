---
title: Importando para um aplicativo usando __declspec(dllimport) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
f1_keywords:
- __declspec
- dllimport
dev_langs:
- C++
helpviewer_keywords:
- __declspec(dllimport) keyword [C++]
- importing DLLs [C++], __declspec(dllimport)
ms.assetid: edb4da4e-f83a-44cf-a668-9239d49dbe42
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 82974ec688fbe688c98188c2e99a54462da81165
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="importing-into-an-application-using-declspecdllimport"></a>Importando para um aplicativo usando __declspec(dllimport)
Um programa que usa os símbolos públicos definidos por uma DLL deve importá-los. Quando você cria arquivos de cabeçalho para aplicativos que usam suas DLLs para criar, usar **__declspec(dllimport)** em declarações dos símbolos públicos. A palavra-chave **__declspec(dllimport)** funciona se você exportar arquivos. def ou com o **dllexport** palavra-chave.  
  
 Para tornar seu código mais legível, definir uma macro para **__declspec(dllimport)** e, em seguida, use a macro para declarar cada símbolo importado:  
  
```  
#define DllImport   __declspec( dllimport )  
  
DllImport int  j;  
DllImport void func();  
```  
  
 Usando **__declspec(dllimport)** é opcional em declarações de função, mas o compilador gera o código mais eficiente se você usar a palavra-chave. No entanto, você deve usar **__declspec(dllimport)** para o executável de importação acessar a DLL símbolos de dados públicos e objetos. Observe que os usuários da sua DLL ainda precisam vincular a uma biblioteca de importação.  
  
 Você pode usar o mesmo arquivo de cabeçalho para a DLL e o aplicativo cliente. Para fazer isso, use um símbolo do pré-processador especial que indica se você está criando a DLL ou compilar o aplicativo cliente. Por exemplo:  
  
```  
#ifdef _EXPORTING  
   #define CLASS_DECLSPEC    __declspec(dllexport)  
#else  
   #define CLASS_DECLSPEC    __declspec(dllimport)  
#endif  
  
class CLASS_DECLSPEC CExampleA : public CObject  
{ ... class definition ... };  
```  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Inicializar uma DLL](../build/run-time-library-behavior.md#initializing-a-dll)  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Importando e exportando funções embutidas](../build/importing-and-exporting-inline-functions.md)  
  
-   [Importações mútuas](../build/mutual-imports.md)  
  
## <a name="see-also"></a>Consulte também  
 [Importando para um aplicativo](../build/importing-into-an-application.md)