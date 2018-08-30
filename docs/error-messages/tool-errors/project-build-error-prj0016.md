---
title: Erro de Build prj0016 do projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0016
dev_langs:
- C++
helpviewer_keywords:
- PRJ0016
ms.assetid: e9745336-883a-4c70-9c40-7753e02f0325
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8c07de9e766b7c2126d0ce4c8d1daed631a8355c
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43194734"
---
# <a name="project-build-error-prj0016"></a>Erro de Build PRJ0016 no Projeto
Configurações de segurança do usuário evitam que o processo que está sendo criado. Essas configurações são necessárias para a compilação.  
  
 Você está conectado como um usuário que não tem permissões para criar processos usando um processo. Você deve alterar os níveis de permissão para esta conta de usuário ou entre em contato com seu administrador da conta.  
  
 Esse erro também pode ocorrer se a seguinte chave do registro é definida:  
  
 \\\HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\RestrictRun  
  
 Para resolver esse erro, exclua a chave de RestrictRun. Se essa chave do registro é necessário, acrescente **vcspawn.exe** à lista de entradas na chave.  
  
 Outra causa desse erro é que sua configuração de política não inclui VCSpawn.exe sob a chave do registro HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\RestrictRun como um programa de janela permitido para esta conta de usuário.  
  
 Para obter mais informações, consulte:  
  
-   Artigo da Base de dados de Conhecimento 324153, que está disponível no [ http://support.microsoft.com/default.aspx?scid=kb; en-us; 324153](http://support.microsoft.com/default.aspx?scid=kb;en-us;324153).  
  
-   [Aderindo às configurações de política do sistema](https://msdn.microsoft.com/library/aa372139), a seção sobre "Executar apenas aplicativos do Windows permitidos".