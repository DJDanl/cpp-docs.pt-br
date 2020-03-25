---
title: /DYNAMICBASE
ms.date: 06/12/2018
f1_keywords:
- /dynamicbase
helpviewer_keywords:
- -DYNAMICBASE editbin option
- DYNAMICBASE editbin option
- /DYNAMICBASE editbin option
ms.assetid: edb3df90-7b07-42fb-a94a-f5a4c1d325d6
ms.openlocfilehash: ab7682c8344d6fc36ded03e7ef885c83d2f19ab7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169039"
---
# <a name="dynamicbase"></a>/DYNAMICBASE

Especifica se uma imagem executável pode ser gerada aleatoriamente com base no tempo de carregamento usando o recurso ASLR (Address Space layout Randomization) do Windows que foi disponibilizado pela primeira vez no Windows Vista.

## <a name="syntax"></a>Sintaxe

> **/DynamicBase**[ **: no**]

## <a name="remarks"></a>Comentários

A opção **/DynamicBase** modifica o cabeçalho de uma *imagem executável*, um arquivo. dll ou. exe, para indicar se o aplicativo deve ser baseado aleatoriamente com base no tempo de carregamento e habilita a randomização de alocação de endereço virtual, que afeta o local da memória virtual de heaps, pilhas e outras alocações do sistema operacional. A opção **/DynamicBase** se aplica a imagens de 32 bits e 64 bits. A ASLR tem suporte no Windows Vista e em sistemas operacionais posteriores. A opção é ignorada pelos sistemas operacionais anteriores.

Por padrão, o **/DynamicBase** está habilitado. Para desabilitar essa opção, use **/DynamicBase: no**. A opção **/DynamicBase** é necessária para que a opção [/HIGHENTROPYVA](highentropyva-support-64-bit-aslr.md) tenha um efeito.

## <a name="see-also"></a>Confira também

- [Opções de EDITBIN](editbin-options.md)
- [Defesas de segurança de software ISV do Windows](https://msdn.microsoft.com/library/bb430720.aspx)
