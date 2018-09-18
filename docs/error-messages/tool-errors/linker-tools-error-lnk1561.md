---
title: Erro das LNK1561 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1561
dev_langs:
- C++
helpviewer_keywords:
- LNK1561
ms.assetid: cb0b709b-7c9c-4496-8a4e-9e1e4aefe447
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ac24ed0c4aff4cbd7f0ea95ff71d0b8c4b3be09c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46050756"
---
# <a name="linker-tools-error-lnk1561"></a>Erro das Ferramentas de Vinculador LNK1561

ponto de entrada deve ser definido.

O vinculador não localizou um *ponto de entrada*, a função inicial a ser chamada em seu executável. Por padrão, o vinculador procura um `main` ou `wmain` função para um aplicativo de console, um `WinMain` ou `wWinMain` função para um aplicativo do Windows, ou `DllMain` para uma DLL que exige inicialização. Você pode especificar o outra função usando o [/ENTRY](../../build/reference/entry-entry-point-symbol.md) a opção de vinculador.

Esse erro pode ter várias causas:
- Você pode não ter incluído o arquivo que define o ponto de entrada na lista de arquivos para vincular. Verifique se que o arquivo que contém a função de ponto de entrada está vinculado ao seu aplicativo.
- Você definiu o ponto de entrada usando a assinatura de função errado; Por exemplo, você pode ter digitado incorretamente usado caso incorreto para o nome de função ou especificado o tipo de retorno ou tipos de parâmetro incorretamente.
- Você não pode ter especificado a [/DLL](../../build/reference/dll-build-a-dll.md) opção ao criar uma DLL.
- Talvez você tenha especificado o nome da função de ponto de entrada incorretamente quando você tiver usado o [/ENTRY](../../build/reference/entry-entry-point-symbol.md) a opção de vinculador.
- Se você estiver usando o [LIB](../../build/reference/lib-reference.md) ferramenta para compilar uma DLL, você pode ter especificado um arquivo. def. Nesse caso, remova o arquivo. def da compilação.

Ao criar um aplicativo, o vinculador procura por uma função de ponto de entrada chamar para iniciar seu código. Essa é a função que é chamada depois que o aplicativo for carregado e o tempo de execução é inicializado. Você deve fornecer uma função de ponto de entrada para um aplicativo ou seu aplicativo não pode ser executado. Um ponto de entrada é opcional para uma DLL. Por padrão, o vinculador procura por uma função de ponto de entrada que tem uma das várias assinaturas e nomes específicos como `int main(int, char**)`. Você pode especificar outro nome de função como a entrada de ponto usando a opção de vinculador /ENTRY.

## <a name="example"></a>Exemplo

O exemplo a seguir gera das LNK1561:

```cpp
// LNK1561.cpp
// LNK1561 expected
int i;
// add a main function to resolve this error
```