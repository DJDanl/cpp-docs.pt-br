---
title: Erro de Build prj0016 no projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: error-reference
f1_keywords:
- PRJ0016
dev_langs:
- C++
helpviewer_keywords:
- PRJ0016
ms.assetid: e9745336-883a-4c70-9c40-7753e02f0325
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 056a033ce95926ca8bbf59e6bbc7b11656fcd015
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="project-build-error-prj0016"></a>Erro de Build PRJ0016 no Projeto
Configurações de segurança do usuário evitam que o processo que está sendo criado. Essas configurações são necessárias para a compilação.  
  
 Você está conectado como um usuário que não tem permissões para criar processos usando um processo. Você deve alterar os níveis de permissão para esta conta de usuário, ou entre em contato com o administrador da conta.  
  
 Esse erro também pode ocorrer se a seguinte chave do registro é definida:  
  
 \\\HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\RestrictRun  
  
 Para resolver esse erro, exclua a chave RestrictRun. Se essa chave do registro é necessário, acrescente **vcspawn.exe** à lista de entradas na chave.  
  
 Outra causa desse erro é que a definição da política não inclui VCSpawn.exe sob a chave do registro HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\RestrictRun como um programa de janela permitido para esta conta de usuário.  
  
 Para obter mais informações, consulte:  
  
-   Artigo da Base de dados de Conhecimento 324153, que está disponível em [http://support.microsoft.com/default.aspx?scid=kb;en-us;324153](http://support.microsoft.com/default.aspx?scid=kb;en-us;324153).  
  
-   [Seguindo as configurações de política do sistema](http://msdn.microsoft.com/library/aa372139), a seção "Executar apenas aplicativos do Windows permitidos".