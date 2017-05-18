---
title: "PRJ0016 de erro de compilação de projeto | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 007ed34cf92222c93ade258bcefd8940c178f86e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="project-build-error-prj0016"></a>Erro de Build PRJ0016 no Projeto
Configurações de segurança do usuário evitam que o processo que está sendo criada. Essas configurações são necessárias para a compilação.  
  
 Você efetuou logon como um usuário que não tem permissões para criar processos usando um processo. Você deve alterar os níveis de permissão para essa conta de usuário ou entre em contato com o administrador da sua conta.  
  
 Esse erro também pode ocorrer se a seguinte chave de registro:  
  
 \\\HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\RestrictRun  
  
 Para resolver esse erro, exclua a chave RestrictRun. Se essa chave do registro é necessário, acrescente **vcspawn.exe** à lista de entradas na chave.  
  
 Outra causa desse erro é que a configuração de política não inclui VCSpawn.exe sob a chave do registro HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\RestrictRun como um programa de janela permitido para esta conta de usuário.  
  
 Para obter informações adicionais, consulte:  
  
-   Artigo da Base de dados de Conhecimento 324153, que está disponível em [http://support.microsoft.com/default.aspx?scid=kb;en-us;324153](http://support.microsoft.com/default.aspx?scid=kb;en-us;324153).  
  
-   [Aderindo às configurações de diretiva do sistema](http://msdn.microsoft.com/library/aa372139), a seção "Executar apenas aplicativos do Windows permitidos".
