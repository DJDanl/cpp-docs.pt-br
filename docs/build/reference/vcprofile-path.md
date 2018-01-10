---
title: VCPROFILE_PATH | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: VCPROFILE_PATH
dev_langs: C++
helpviewer_keywords: VCPROFILE_PATH environment variable
ms.assetid: 25217aa4-7e86-4eba-854d-10b3c457e4df
caps.latest.revision: "4"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ea682b70f4417ef49bfca530af5f12f21699a389
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="vcprofilepath"></a>VCPROFILE_PATH
Especifique o diretório para criar arquivos. PGC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
VCPROFILE_PATH=path  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `path`  
 O caminho do diretório no qual. PGC arquivos serão adicionados.  
  
## <a name="remarks"></a>Comentários  
 Por padrão, os arquivos. PGC são criados no mesmo diretório que o binário que está sendo analisado.  No entanto, se o caminho absoluto do binário não existir, que pode ser o caso quando você executa os cenários de perfil em um computador diferente de onde o binário foi criado, você pode definir `VCPROFILE_PATH` para um caminho existente.  
  
## <a name="example"></a>Exemplo  
  
```  
set VCPROFILE_PATH=c:\  
```  
  
## <a name="see-also"></a>Consulte também  
 [Variáveis de ambiente para otimizações guiadas por perfil](../../build/reference/environment-variables-for-profile-guided-optimizations.md)