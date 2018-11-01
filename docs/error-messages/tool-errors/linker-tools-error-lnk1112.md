---
title: Erro das Ferramentas de Vinculador LNK1112
ms.date: 11/04/2016
f1_keywords:
- LNK1112
helpviewer_keywords:
- LNK1112
ms.assetid: 425793d8-37e6-4072-9b6e-c3d4e9c12562
ms.openlocfilehash: bc01d56fb8144d23b91c82a7f791a70a5dadb7ef
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50607084"
---
# <a name="linker-tools-error-lnk1112"></a>Erro das Ferramentas de Vinculador LNK1112

> tipo de máquina do módulo '*type1*'está em conflito com tipo de máquina de destino'*type2*'

## <a name="remarks"></a>Comentários

Os arquivos de objeto especificados como entrada foram compilados para tipos de computador diferente.

Por exemplo, se você tentar vincular um arquivo de objeto compilado com **/clr** e um arquivo de objeto compilado com **/clr: pure** (CEE do tipo de computador), o vinculador gerará o erro das LNK1112. O **/clr: pure** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Da mesma forma, se você criar um módulo com x64 compilador e o outro módulo com x86 compilador e tente para vinculá-los, o vinculador gerará das LNK1112.

Um motivo possível para esse erro é se você estiver desenvolvendo um aplicativo de 64 bits, mas não tiver instalado um dos compiladores de 64 do Visual C++-bit. Nesse caso, as configurações de 64 bits não estará disponíveis. Para corrigir esse problema, execute o instalador do Visual Studio e instalar os componentes ausentes do C++.

Esse erro também pode ocorrer se você alterar o **configuração da solução ativa** na **Configuration Manager** e, em seguida, tentar compilar o projeto antes de excluir os arquivos intermediários do projeto. Para resolver esse erro, selecione **recompilar solução** da **Build** menu. Você também pode selecionar **limpar solução** da **Build** menu e, em seguida, compilar a solução.

## <a name="see-also"></a>Consulte também

- [Erros e avisos das ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-errors-and-warnings.md)
