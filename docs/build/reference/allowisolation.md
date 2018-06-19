---
title: -ALLOWISOLATION | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /ALLOWISOLATION
dev_langs:
- C++
helpviewer_keywords:
- -ALLOWISOLATION editbin option
- /ALLOWISOLATION editbin option
- ALLOWISOLATION editbin option
ms.assetid: 91430344-f64f-491a-a5a5-7ea3b21cbe68
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5cb92a7f31d48dad4a7fb608703c71ccc661e176
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32368968"
---
# <a name="allowisolation"></a>/ALLOWISOLATION
Especifica o comportamento da pesquisa de manifesto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
/ALLOWISOLATION[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 **/ALLOWISOLATION** faz com que o sistema operacional ao manifesto pesquisas e carrega.  
  
 **/ALLOWISOLATION** é o padrão.  
  
 **/ALLOWISOLATION:no** indica que os executáveis sejam carregados como não se houvesse nenhum manifesto e causas [referência de EDITBIN](../../build/reference/editbin-reference.md) para definir o `IMAGE_DLLCHARACTERISTICS_NO_ISOLATION` bit do cabeçalho opcional `DllCharacteristics` campo.  
  
 Quando o isolamento é desabilitado por um executável, o carregador do Windows não tenta encontrar um manifesto de aplicativo para o processo criado recentemente. O novo processo não tem um contexto de ativação padrão, mesmo se houver um manifesto no executável em si ou se houver um manifesto que tem o nome *nome executável*. manifest.  
  
## <a name="see-also"></a>Consulte também  
 [Opções EDITBIN](../../build/reference/editbin-options.md)   
 [/ALLOWISOLATION (pesquisa de manifesto)](../../build/reference/allowisolation-manifest-lookup.md)   
 [Referência de arquivos de manifesto](http://msdn.microsoft.com/library/aa375632.aspx)