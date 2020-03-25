---
title: Erro das Ferramentas de Vinculador LNK1561
ms.date: 11/04/2016
f1_keywords:
- LNK1561
helpviewer_keywords:
- LNK1561
ms.assetid: cb0b709b-7c9c-4496-8a4e-9e1e4aefe447
ms.openlocfilehash: 706cf6c90dc187b6c343edc82cebb93bb8660452
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194844"
---
# <a name="linker-tools-error-lnk1561"></a>Erro das Ferramentas de Vinculador LNK1561

o ponto de entrada deve ser definido

O vinculador não encontrou um *ponto de entrada*, a função inicial a ser chamada no seu executável. Por padrão, o vinculador procura uma função `main` ou `wmain` para um aplicativo de console, uma função `WinMain` ou `wWinMain` para um aplicativo do Windows ou `DllMain` para uma DLL que requer inicialização. Você pode especificar outra função usando a opção de vinculador [/entry](../../build/reference/entry-entry-point-symbol.md) .

Esse erro pode ter várias causas:
- Talvez você não tenha incluído o arquivo que define seu ponto de entrada na lista de arquivos a serem vinculados. Verifique se o arquivo que contém a função de ponto de entrada está vinculado ao seu aplicativo.
- Você pode ter definido o ponto de entrada usando a assinatura de função incorreta; por exemplo, você pode ter digitado incorretamente ou usado o caso incorreto para o nome da função ou especificar o tipo de retorno ou os tipos de parâmetro incorretamente.
- Talvez você não tenha especificado a opção [/dll](../../build/reference/dll-build-a-dll.md) ao criar uma dll.
- Você pode ter especificado o nome da função de ponto de entrada incorretamente quando usou a opção de vinculador [/entry](../../build/reference/entry-entry-point-symbol.md) .
- Se você estiver usando a ferramenta [lib](../../build/reference/lib-reference.md) para criar uma dll, talvez tenha especificado um arquivo. def. Nesse caso, remova o arquivo. def da compilação.

Ao criar um aplicativo, o vinculador procura uma função de ponto de entrada para chamar para iniciar seu código. Essa é a função que é chamada depois que o aplicativo é carregado e o tempo de execução é inicializado. Você deve fornecer uma função de ponto de entrada para um aplicativo ou seu aplicativo não pode ser executado. Um ponto de entrada é opcional para uma DLL. Por padrão, o vinculador procura uma função de ponto de entrada que tenha um dos vários nomes e assinaturas específicos, como `int main(int, char**)`. Você pode especificar outro nome de função como o ponto de entrada usando a opção de vinculador/ENTRY.

## <a name="example"></a>Exemplo

O exemplo a seguir gera LNK1561:

```cpp
// LNK1561.cpp
// LNK1561 expected
int i;
// add a main function to resolve this error
```
