---
title: Importação para um aplicativo usando __declspec(dllimport)
ms.date: 11/04/2016
helpviewer_keywords:
- __declspec(dllimport) keyword [C++]
- importing DLLs [C++], __declspec(dllimport)
ms.assetid: edb4da4e-f83a-44cf-a668-9239d49dbe42
ms.openlocfilehash: fd7d42ec5a76b92aa789a3a20f38e6b2c0fd2cb1
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440412"
---
# <a name="import-into-an-application-using-__declspecdllimport"></a>Importação para um aplicativo usando __declspec(dllimport)

Um programa que usa símbolos públicos definidos por uma DLL é considerado para importá-los. Quando você cria arquivos de cabeçalho para aplicativos que usam suas DLLs para criar com, use **__declspec (dllimport)** nas declarações dos símbolos públicos. A palavra-chave **__declspec (dllimport)** funciona independentemente de você exportar com arquivos. def ou com a palavra-chave **__declspec (dllexport)** .

Para tornar seu código mais legível, defina uma macro para **__declspec (dllimport)** e, em seguida, use a macro para declarar cada símbolo importado:

```
#define DllImport   __declspec( dllimport )

DllImport int  j;
DllImport void func();
```

O uso de **__declspec (dllimport)** é opcional em declarações de função, mas o compilador produz um código mais eficiente se você usar essa palavra-chave. No entanto, você deve usar **__declspec (dllimport)** para que o executável de importação acesse os símbolos e objetos de dados públicos da dll. Observe que os usuários da sua DLL ainda precisam vincular a uma biblioteca de importação.

Você pode usar o mesmo arquivo de cabeçalho para a DLL e o aplicativo cliente. Para fazer isso, use um símbolo de pré-processador especial que indica se você está criando a DLL ou criando o aplicativo cliente. Por exemplo:

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

- [Inicializar uma DLL](run-time-library-behavior.md#initializing-a-dll)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Importação e exportação de funções embutidas](importing-and-exporting-inline-functions.md)

- [Importações mútuas](mutual-imports.md)

## <a name="see-also"></a>Consulte também

[Importando para um aplicativo](importing-into-an-application.md)
