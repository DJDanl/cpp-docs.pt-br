---
title: Exportando a partir de uma DLL usando __declspec(dllexport)
ms.date: 11/04/2016
f1_keywords:
- dllexport
- __declspec
helpviewer_keywords:
- __declspec(dllexport) keyword [C++]
- names [C++], DLL exports by
- export directives [C++]
- exporting DLLs [C++], __declspec(dllexport) keyword
ms.assetid: a35e25e8-7263-4a04-bad4-00b284458679
ms.openlocfilehash: effefa2c370634c450b03ed18187769e12e40adf
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50500380"
---
# <a name="exporting-from-a-dll-using-declspecdllexport"></a>Exportando a partir de uma DLL usando __declspec(dllexport)

Microsoft introduzido **export** na versão de compilador de 16 bits do Visual C++ para permitir que o compilador a gerar os nomes de exportação automaticamente e colocá-los em um arquivo. lib. Esse arquivo. lib, em seguida, pode ser usado como um. lib estático para vincular a uma DLL.

Em versões mais recentes do compilador, você pode exportar dados, funções, classes ou funções de membro de classe de uma DLL usando o **dllexport** palavra-chave. **dllexport** adiciona a diretiva de exportação para o arquivo de objeto, você não precisa usar um arquivo. def.

Esta conveniência é mais aparente quando tentar exportar nomes de função de C++ decorados. Como não há nenhuma especificação padrão para a decoração de nome, o nome de uma função exportada pode alterar entre versões do compilador. Se você usar **dllexport**, recompilação da DLL e arquivos dependentes .exe é necessário apenas para conta quaisquer alterações de convenção de nomenclatura.

Muitas diretivas de exportação, como ordinais, NONAME e PRIVATE, podem ser feitas somente em um arquivo. def, e não é possível especificar esses atributos sem um arquivo. def. No entanto, usando **dllexport** além de usar um. def arquivo não causa erros de compilação.

Para exportar funções, o **dllexport** palavra-chave deve aparecer à esquerda da palavra-chave a convenção de chamada, se uma palavra-chave for especificada. Por exemplo:

```
__declspec(dllexport) void __cdecl Function1(void);
```

Para exportar todos os membros de dados públicos e funções de membro em uma classe, a palavra-chave deve aparecer à esquerda do nome da classe, da seguinte maneira:

```
class __declspec(dllexport) CExampleExport : public CObject
{ ... class definition ... };
```

> [!NOTE]
>  `__declspec(dllexport)` não pode ser aplicado a uma função com o `__clrcall` convenção de chamada.

Ao criar sua DLL, você normalmente cria um arquivo de cabeçalho que contém os protótipos de função e/ou classes que você está exportando e adiciona **dllexport** às declarações no arquivo de cabeçalho. Para tornar seu código mais legível, defina uma macro para **dllexport** e usar a macro com cada símbolo que você estiver exportando:

```
#define DllExport   __declspec( dllexport )
```

**dllexport** armazena nomes na tabela de exportação da DLL de função. Se você deseja otimizar o tamanho da tabela, consulte [exportar funções de uma DLL por Ordinal em vez de por nome](../build/exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md).

> [!NOTE]
>  Ao portar o código-fonte DLL do Win16 para Win32, substitua cada instância do **export** com **dllexport**.

Como uma referência, pesquise por meio do arquivo de cabeçalho WinBase Win32. Ele contém exemplos de **__declspec(dllimport)** uso.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL usando arquivos. def](../build/exporting-from-a-dll-using-def-files.md)

- [Exportar e importar usando AFX_EXT_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)

- [Exportar funções de C++ para uso em executáveis da linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Exportar funções de C para uso em executáveis C ou da linguagem C++](../build/exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)

- [Determinar qual método de exportação usar](../build/determining-which-exporting-method-to-use.md)

- [Importar para um aplicativo usando __declspec(dllimport)](../build/importing-into-an-application-using-declspec-dllimport.md)

- [Inicialize um DLL](../build/run-time-library-behavior.md#initializing-a-dll)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [A palavra-chave declspec](../cpp/declspec.md)

- [Importando e exportando funções embutidas](../build/importing-and-exporting-inline-functions.md)

- [Importações mútuas](../build/mutual-imports.md)

## <a name="see-also"></a>Consulte também

[Exportando de uma DLL](../build/exporting-from-a-dll.md)