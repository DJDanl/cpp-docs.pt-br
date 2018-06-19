---
title: Desenvolver sua própria função auxiliar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- helper functions
ms.assetid: a845429d-68b1-4e14-aa88-f3f5343bd490
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e6b8e397fecc8f14140cd7c86217421d5aa1a749
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32371392"
---
# <a name="developing-your-own-helper-function"></a>Desenvolvendo a função auxiliar própria
Você talvez queira fornecer sua própria versão da rotina para fazer o processamento específico com base nos nomes da DLL ou importações. Há duas maneiras de fazer isso: codificação de sua preferência, possivelmente com base em código fornecido, ou simplesmente conectando a versão fornecida com os ganchos de notificação detalhados anteriormente.  
  
 Código de seu próprio  
 Isso é bastante simple, pois você essencialmente pode usar o código fornecido como uma diretriz para uma nova. Naturalmente, ela deve estar de acordo com as convenções de chamada e se ele retorna para as conversões geradas pelo vinculador, ele deve retornar um ponteiro de função apropriada. Uma vez em seu código, você pode fazer quase tudo o que quiser para atender a chamada ou tirar proveito de chamada.  
  
 Usar o início do processamento de gancho de notificação  
 Provavelmente será mais fácil simplesmente fornecer um ponteiro para uma função de gancho de notificação fornecido pelo usuário que recebe os mesmos valores que o auxiliar padrão em dliStartProcessing a notificação. Nesse ponto, a função de gancho pode essencialmente se tornar a nova função de auxiliar, como um retorno bem-sucedido para o auxiliar padrão ignorará todos os processamento no auxiliar de padrão.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)