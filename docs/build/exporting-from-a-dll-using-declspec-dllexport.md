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
ms.openlocfilehash: 075962758773660085ae0b98b668c264524cc6aa
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328589"
---
# <a name="exporting-from-a-dll-using-__declspecdllexport"></a>Exportando a partir de uma DLL usando __declspec(dllexport)

Você pode exportar dados, funções, classes ou funções de membro de classe a partir de uma DLL usando a palavra-chave **__declspec(dllexport).** **__declspec(dllexport)** adiciona a diretiva de exportação ao arquivo objeto para que você não precise usar um arquivo .def.

Essa conveniência é mais evidente ao tentar exportar nomes de funções C++ decorados. Como não há uma especificação padrão para a decoração do nome, o nome de uma função exportada pode mudar entre as versões do compilador. Se você usar **__declspec(dllexport)**, a recompilação dos arquivos DLL e .exe dependente é necessária apenas para explicar quaisquer alterações na convenção de nomeação.

Muitas diretivas de exportação, como ordinals, NONAME e PRIVATE, podem ser feitas apenas em um arquivo .def, e não há como especificar esses atributos sem um arquivo .def. No entanto, usar **__declspec(dllexport)** além de usar um arquivo .def não causa erros de compilação.

Para exportar funções, a palavra-chave **__declspec (dllexport)** deve aparecer à esquerda da palavra-chave da convenção de chamada, se uma palavra-chave for especificada. Por exemplo:

```
__declspec(dllexport) void __cdecl Function1(void);
```

Para exportar todos os membros de dados públicos e funções de membros em uma classe, a palavra-chave deve aparecer à esquerda do nome da classe da seguinte forma:

```
class __declspec(dllexport) CExampleExport : public CObject
{ ... class definition ... };
```

> [!NOTE]
> `__declspec(dllexport)`não pode ser aplicado a `__clrcall` uma função com a convenção de chamada.

Ao criar sua DLL, você normalmente cria um arquivo de cabeçalho que contém os protótipos de função e/ou classes que você está exportando e adiciona **__declspec(dllexport)** às declarações no arquivo de cabeçalho. Para tornar seu código mais legível, defina uma macro para **__declspec(dllexport)** e use a macro com cada símbolo que você está exportando:

```
#define DllExport   __declspec( dllexport )
```

**__declspec (dllexport)** armazena nomes de função na tabela de exportação da DLL. Se você quiser otimizar o tamanho da tabela, consulte [Funções de exportação de uma DLL por Ordinal Em Vez de pelo Nome](exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md).

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL usando arquivos .def](exporting-from-a-dll-using-def-files.md)

- [Exportação e importação usando AFX_EXT_CLASS](exporting-and-importing-using-afx-ext-class.md)

- [Exportar funções C++ para uso em executáveis em linguagem C](exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Funções de exportação C para uso em executáveis c ou c++-ling](exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)

- [Determinar qual método de exportação usar](determining-which-exporting-method-to-use.md)

- [Importação para um aplicativo usando __declspec(dllimport)](importing-into-an-application-using-declspec-dllimport.md)

- [Inicialize um DLL](run-time-library-behavior.md#initializing-a-dll)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [A palavra-chave __declspec](../cpp/declspec.md)

- [Importação e exportação de funções embutidas](importing-and-exporting-inline-functions.md)

- [Importações mútuas](mutual-imports.md)

## <a name="see-also"></a>Confira também

[Exportando a partir de uma DLL](exporting-from-a-dll.md)
