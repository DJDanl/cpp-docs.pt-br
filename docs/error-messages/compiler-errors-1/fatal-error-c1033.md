---
title: Erro fatal C1033 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1033
dev_langs:
- C++
helpviewer_keywords:
- C1033
ms.assetid: 09976c03-8450-4cf7-8b43-1b91c2c2b9f9
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: a0c9c67d23f2d0b957fb3e43844245029efedc64
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1033"></a>Erro fatal C1033
não é possível abrir pdb de banco de dados do programa  
  
 Esse erro pode ser causado por um erro de disco.  
  
 No Visual C++ .NET 2002, a localidade do usuário deve ser definida corretamente quando o nome de arquivo (ou o caminho de diretório para o nome do arquivo) contém caracteres MBCS. Definir a localidade do sistema não é suficiente; a localidade do usuário deve ser configurada para processar caracteres MBCS.  
  
 Para obter mais informações, consulte [http://support.microsoft.com/default.aspx?scid=kb;en-us;246007](http://support.microsoft.com/default.aspx?scid=kb;en-us;246007).
