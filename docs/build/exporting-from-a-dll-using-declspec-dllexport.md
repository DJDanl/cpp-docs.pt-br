---
title: Exportando a partir de uma DLL usando __declspec(dllexport)
ms.date: 05/06/2019
f1_keywords:
- dllexport
helpviewer_keywords:
- __declspec(dllexport) keyword [C++]
- names [C++], DLL exports by
- export directives [C++]
- exporting DLLs [C++], __declspec(dllexport) keyword
ms.assetid: a35e25e8-7263-4a04-bad4-00b284458679
ms.openlocfilehash: c84a8eca25c90e0790ec8c4991d9d5a116afa59f
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79442532"
---
# <a name="exporting-from-a-dll-using-__declspecdllexport"></a>Exportando a partir de uma DLL usando __declspec(dllexport)

Você pode exportar dados, funções, classes ou funções de membro de classe de uma DLL usando a palavra-chave **__declspec (dllexport)** . **__declspec (dllexport)** adiciona a diretiva de exportação ao arquivo de objeto para que você não precise usar um arquivo. def.

Essa conveniência é mais aparente ao tentar exportar nomes de C++ funções decorados. Como não há especificação padrão para decoração de nome, o nome de uma função exportada pode ser alterado entre as versões do compilador. Se você usar **__declspec (dllexport)** , a recompilação da dll e dos arquivos. exe dependentes só serão necessários para a conta de qualquer alteração de Convenção de nomenclatura.

Muitas diretivas de exportação, como ordinais, NONAME e PRIVATE, só podem ser feitas em um arquivo. def, e não há como especificar esses atributos sem um arquivo. def. No entanto, usar **__declspec (dllexport)** , além de usar um arquivo. def, não causa erros de compilação.

Para exportar funções, a palavra-chave **__declspec (dllexport)** deve aparecer à esquerda da palavra-chave da Convenção de chamada, se uma palavra-chave for especificada. Por exemplo:

```
__declspec(dllexport) void __cdecl Function1(void);
```

Para exportar todos os membros de dados públicos e as funções de membro em uma classe, a palavra-chave deve aparecer à esquerda do nome da classe, da seguinte maneira:

```
class __declspec(dllexport) CExampleExport : public CObject
{ ... class definition ... };
```

> [!NOTE]
>  `__declspec(dllexport)` não pode ser aplicado a uma função com a Convenção de chamada `__clrcall`.

Ao criar sua DLL, você normalmente cria um arquivo de cabeçalho que contém os protótipos de função e/ou classes que você está exportando e adiciona **__declspec (dllexport)** às declarações no arquivo de cabeçalho. Para tornar seu código mais legível, defina uma macro para **__declspec (dllexport)** e use a macro com cada símbolo que você está exportando:

```
#define DllExport   __declspec( dllexport )
```

**__declspec (dllexport)** armazena os nomes de função na tabela de exportação da dll. Se você quiser otimizar o tamanho da tabela, consulte [Exportando funções de uma DLL por ordinal em vez de por nome](exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md).

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL usando arquivos. def](exporting-from-a-dll-using-def-files.md)

- [Exportar e importar usando o AFX_EXT_CLASS](exporting-and-importing-using-afx-ext-class.md)

- [Exportar C++ funções para uso em executáveis de linguagem C](exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Exportar funções C para uso em executáveis C++de linguagem C ou-](exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)

- [Determinar qual método de exportação usar](determining-which-exporting-method-to-use.md)

- [Importação para um aplicativo usando __declspec(dllimport)](importing-into-an-application-using-declspec-dllimport.md)

- [Inicializar uma DLL](run-time-library-behavior.md#initializing-a-dll)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [A palavra-chave __declspec](../cpp/declspec.md)

- [Importação e exportação de funções embutidas](importing-and-exporting-inline-functions.md)

- [Importações mútuas](mutual-imports.md)

## <a name="see-also"></a>Consulte também

[Exportando de uma DLL](exporting-from-a-dll.md)
