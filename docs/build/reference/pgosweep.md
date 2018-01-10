---
title: pgosweep | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- pgosweep program
- profile-guided optimizations, pgosweep
ms.assetid: f39dd3b7-1cd9-4c3b-8e8b-fb794744b757
caps.latest.revision: "22"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 78ae6c36011e3c10359988cf2c501514d1bcf70a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="pgosweep"></a>pgosweep
Usado na Otimização Guiada por perfil para gravar todos os dados de perfil de um programa em execução para o arquivo. PGC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
pgosweep [options] image pgcfile  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `options`  
 Um parâmetro opcional que pode ser deixado em branco. Os valores válidos para `options` são da seguinte maneira:  
  
-   **/?** ou **/help,** exibe a mensagem de Ajuda.  
  
-   **/NoReset,** preserva a contagem de estruturas de dados de tempo de execução.  
  
 `image`  
 O caminho completo de um arquivo .exe ou. dll que foi criado usando o /LTCG:PGINSTRUMENT de opção de compilador.  
  
 `pgcfile`  
 O arquivo. PGC onde esse comando gravará os dados de contagens.  
  
## <a name="remarks"></a>Comentários  
 Esse comando funciona em programas que foram criados com a opção de compilador /LTCG:PGINSTRUMENT. Ele interrompe um programa em execução e grava os dados de perfil para um novo arquivo. PGC. Por padrão, o comando redefine contagens após cada operação de gravação. Se você especificar o **/noreset** opção, o comando registrar os valores, mas não redefini-las no programa em execução. Esta opção fornecerá dados duplicados se você recuperar os dados de perfil mais tarde.  
  
 A alternativa de usar para `pgosweep` é para recuperar informações de perfil apenas para o tempo de execução do aplicativo. Por exemplo, você pode executar `pgosweep` logo depois de iniciar o aplicativo e descartar o arquivo. Isso removerá os dados de perfil associados com os custos de inicialização. Em seguida, você pode executar `pgosweep` antes de encerrar o aplicativo. Agora os dados coletados tem informações de perfil somente de tempo de execução.  
  
 Ao nomear um arquivo. PGC (`pgcfile`) você pode usar o formato padrão, que é *appname! n*. PGC. Se você usar esse formato, o compilador encontrará esses dados na fase de /LTCG:PGO. Se você não usa o formato padrão, você deve usar [pgomgr](../../build/reference/pgomgr.md) para mesclar os arquivos. PGC.  
  
## <a name="example"></a>Exemplo  
  
```  
pgosweep myapp.exe myapp!1.pgc  
```  
  
 Neste exemplo, `pgosweep` grava as informações de perfil atual para myapp.exe myapp!1.pgc.  
  
## <a name="see-also"></a>Consulte também  
 [Ferramentas para otimização guiada por perfil manual](../../build/reference/tools-for-manual-profile-guided-optimization.md)