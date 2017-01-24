---
title: "Erro PRJ0016 (compila&#231;&#227;o de projeto) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "PRJ0016"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PRJ0016"
ms.assetid: e9745336-883a-4c70-9c40-7753e02f0325
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro PRJ0016 (compila&#231;&#227;o de projeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As configurações de segurança do usuário evitam que o processo seja criado.Essas configurações são necessárias para a compilação.  
  
 Você está conectado como um usuário que não tem permissões para criar processos usando um processo.  Você deve alterar os níveis de permissão para esta conta de usuário, ou contate o administrador de conta.  
  
 Esse erro também poderá ocorrer se a chave do Registro a seguir é definida:  
  
 \\\\HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\RestrictRun  
  
 Para resolver este erro, exclua a chave de RestrictRun.  Se essa chave de Registro é necessária, anexar **vcspawn.exe** à lista de entradas na chave.  
  
 Outra causa desse erro é que sua configuração de política não inclui VCSpawn.exe na chave do Registro HKEY\_CURRENT\_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\RestrictRun como um programa permitido da janela para esta conta de usuário.  
  
 Para obter mais informações, consulte:  
  
-   Artigo da Base de Dados de Conhecimento 324153, que está disponível em [http:\/\/support.microsoft.com\/default.aspx?scid\=kb;en\-us;324153](http://support.microsoft.com/default.aspx?scid=kb;en-us;324153).  
  
-   [A aderência às configurações de política do sistema](http://msdn.microsoft.com/library/aa372139), a seção “em aplicativos do Windows permitidos apenas execução”.