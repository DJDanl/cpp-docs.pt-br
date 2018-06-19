---
title: Constantes confirmar em disco | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- vc.constants
dev_langs:
- C++
helpviewer_keywords:
- commit-to-disk constants
ms.assetid: 0b903b23-b4fa-431e-a937-51d95f695ecf
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3c3a815948c127c5dec0fe6412ab3c358aa409e2
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32391058"
---
# <a name="commit-to-disk-constants"></a>Constantes confirmar em disco
**Seção específica da Microsoft**  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#include <stdio.h>  
```  
  
## <a name="remarks"></a>Comentários  
 Essas constantes específicas da Microsoft especificam se o buffer associado ao arquivo aberto é liberado para os buffers do sistema operacional ou para o disco. O modo é incluído na cadeia de caracteres que especifica o tipo de acesso de leitura/gravação (**"r"**, **"w"**, **"a"**, **"r +"**, **"w +"**, **"+"**).  
  
 Os modos de confirmar em disco são os seguintes:  
  
 **c**  
 Grava os conteúdos não gravados do buffer especificado no disco. A funcionalidade confirmar em disco ocorre somente em chamadas explícitas para a função [fflush](../c-runtime-library/reference/fflush.md) ou [_flushall](../c-runtime-library/reference/flushall.md). Esse modo é útil ao lidar com dados confidenciais. Por exemplo, se o seu programa terminar após uma chamada para `fflush` ou `_flushall`, você pode ter certeza de que seus dados alcançaram os buffers do sistema operacional. No entanto, a menos que um arquivo seja aberto com a opção **c**, os dados podem nunca alcançar o disco se o sistema operacional terminar também.  
  
 **n**  
 Grava os conteúdos não gravados do buffer especificado nos buffers do sistema operacional. O sistema operacional pode armazenar dados em cache e depois determinar o melhor momento para gravar em disco. Em muitas condições, esse comportamento gera um comportamento eficiente do programa. No entanto, se a retenção de dados for crítica (por exemplo, transações bancárias ou informações de bilhetes de aéreos), considere o uso da opção **c**. O modo **n** é o padrão.  
  
> [!NOTE]
>  As opções **c** e **n** não fazem parte do padrão ANSI para `fopen`, mas são extensões da Microsoft e não devem ser usadas quando se desejar portabilidade ANSI.  
  
## <a name="using-the-commit-to-disk-feature-with-existing-code"></a>Usar o recurso Confirmar em disco com código existente  
 Por padrão, chamadas para as funções de biblioteca [fflush](../c-runtime-library/reference/fflush.md) ou [_flushall](../c-runtime-library/reference/flushall.md) gravam dados em buffers mantidos pelo sistema operacional. O sistema operacional determina o momento ideal para gravar os dados no disco. O recurso confirmar em disco da biblioteca em tempo de execução permite assegurar que dados críticos sejam gravados diretamente no disco em vez de em buffers do sistema operacional. Você pode fornecer esse recurso a um programa existente sem reescrevê-lo ao vincular os arquivos-objeto a COMMODE.OBJ.  
  
 No arquivo executável resultante, chamadas para `fflush` gravam o conteúdo do buffer diretamente no disco e chamadas para `_flushall` gravam o conteúdo de todos os buffers no disco. Essas duas funções são as únicas afetadas por COMMODE.OBJ.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../c-runtime-library/stream-i-o.md)   
 [_fdopen, _wfdopen](../c-runtime-library/reference/fdopen-wfdopen.md)   
 [fopen, _wfopen](../c-runtime-library/reference/fopen-wfopen.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)