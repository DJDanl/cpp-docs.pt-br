---
title: PogoSafeMode | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- PogoSafeMode
ms.assetid: 2daeeff7-44cb-417f-90eb-6b9edf658533
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5f40dad6feff9e49deeb495e8acbf2584dea3e41
ms.sourcegitcommit: 5cd2e3e51ecc8d9fc0d889555b4bfa193ba1d6a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2018
---
# <a name="pogosafemode"></a>PogoSafeMode
Especifique se deseja usar o modo rápido ou modo de segurança para a criação de perfil de aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
PogoSafeMode  
```  
  
## <a name="remarks"></a>Comentários  
 Otimização Guiada por perfil (PGO) tem dois modos possíveis durante a fase de criação de perfil: rápida modo e o modo de segurança. Quando a criação de perfil está no modo rápido, ele usa o **INC** instrução para aumentar os contadores de dados. O **INC** instrução é mais rápida, mas não é thread-safe. Quando a criação de perfil está no modo de segurança, ele usa o **LOCK INC** instrução para aumentar os contadores de dados. O **LOCK INC** instrução tem a mesma funcionalidade que o **INC** instrução tem e é thread-safe, mas é mais lenta que a **INC** instrução.  
  
 Por padrão, a criação de perfil de PGO opera em modo rápido. `PogoSafeMode` é necessário apenas se você deseja usar o modo de segurança.  
  
 Para executar a criação de perfil PGO no modo de segurança, você deve usar a variável de ambiente `PogoSafeMode` ou a opção de vinculador **- PogoSafeMode**, dependendo do sistema. Se você estiver executando a criação de perfil em um x64 computador, você deve usar a opção de vinculador. Se você estiver executando a criação de perfil em um x86 computador, você deve definir a variável de ambiente para qualquer valor antes de iniciar o processo de otimização.  
  
## <a name="example"></a>Exemplo  
  
```  
set PogoSafeMode=1  
```  
  
## <a name="see-also"></a>Consulte também  
 [Variáveis de ambiente para otimizações guiadas por perfil](../../build/reference/environment-variables-for-profile-guided-optimizations.md)   
 [Otimizações guiadas por perfil](../../build/reference/profile-guided-optimizations.md)