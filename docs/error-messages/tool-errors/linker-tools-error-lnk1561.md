---
title: Erro das Ferramentas de Vinculador LNK1561
ms.date: 11/04/2016
f1_keywords:
- LNK1561
helpviewer_keywords:
- LNK1561
ms.assetid: cb0b709b-7c9c-4496-8a4e-9e1e4aefe447
ms.openlocfilehash: b397ef8e551f8cd6179392541e35183a5850454f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81357744"
---
# <a name="linker-tools-error-lnk1561"></a>Erro das Ferramentas de Vinculador LNK1561

ponto de entrada deve ser definido

O linker não encontrou um *ponto de entrada,* a função inicial para chamar em seu executável. Por padrão, o linker `main` `wmain` procura uma ou função `WinMain` `wWinMain` para um aplicativo de `DllMain` console, uma ou função para um aplicativo Windows ou para uma DLL que requer inicialização. Você pode especificar outra função usando a opção [linker /ENTRY.](../../build/reference/entry-entry-point-symbol.md)

Este erro pode ter várias causas:

- Você pode não ter incluído o arquivo que define seu ponto de entrada na lista de arquivos a serem link. Verifique se o arquivo que contém a função de ponto de entrada está vinculado ao seu aplicativo.
- Você pode ter definido o ponto de entrada usando a assinatura da função errada; por exemplo, você pode ter escrito errado ou usado o caso errado para o nome da função, ou especificado os tipos de retorno ou parâmetro sem erro.
- Você pode não ter especificado a opção [/DLL](../../build/reference/dll-build-a-dll.md) ao construir uma DLL.
- Você pode ter especificado o nome da função de ponto de entrada incorretamente quando usou a opção [linker /ENTRY.](../../build/reference/entry-entry-point-symbol.md)
- Se você estiver usando a ferramenta [LIB](../../build/reference/lib-reference.md) para construir um DLL, você pode ter especificado um arquivo .def. Em caso for, remova o arquivo .def da compilação.

Ao criar um aplicativo, o linker procura uma função de ponto de entrada para ligar para iniciar seu código. Esta é a função que é chamada depois que o aplicativo é carregado e o tempo de execução é inicializado. Você deve fornecer uma função de ponto de entrada para um aplicativo, ou seu aplicativo não pode ser executado. Um ponto de entrada é opcional para uma DLL. Por padrão, o linker procura uma função de ponto de entrada `int main(int, char**)`que tenha um dos vários nomes e assinaturas específicos, tais como . Você pode especificar outro nome de função como ponto de entrada usando a opção linker /ENTRY.

## <a name="example"></a>Exemplo

A seguinte amostra gera LNK1561:

```cpp
// LNK1561.cpp
// LNK1561 expected
int i;
// add a main function to resolve this error
```
