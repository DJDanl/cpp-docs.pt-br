---
title: "Chamar Scripts | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "StringRegister"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método StringRegister"
  - "scripts, invocando o registro em ATL"
ms.assetid: eabd41ee-586b-4266-9e92-5aaad04b73a4
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Chamar Scripts
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[Usando parâmetros substituíveis \(do registrador o pré\-processador\)](../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md) aborda os mapas de substituição e menciona o método registrador **AddReplacement**. O registrador tem oito outros métodos específicos aos scripts e todas são descritas na tabela a seguir.  
  
|Método|Descrição da sintaxe \/|  
|------------|-----------------------------|  
|**ResourceRegister**|**HRESULT ResourceRegister \(LPCOLESTR**  *resFileName* **, UINT**  `nID` **, LPCOLESTR**  `szType` **\);**<br /><br /> Registra o script contido no recurso do módulo.*resFileName* indica o caminho UNC para o próprio módulo.`nID` e `szType` contêm a ID do recurso e o tipo, respectivamente.|  
|**ResourceUnregister**|**HRESULT ResourceUnregister \(LPCOLESTR**  *resFileName* **, UINT**  `nID` **, LPCOLESTR**  `szType` **\);**<br /><br /> Cancela o script contido no recurso do módulo.*resFileName* indica o caminho UNC para o próprio módulo.`nID` e `szType` contêm a ID do recurso e o tipo, respectivamente.|  
|**ResourceRegisterSz**|**HRESULT ResourceRegisterSz \(LPCOLESTR**  *resFileName* **, LPCOLESTR**  *szID* **, LPCOLESTR**  `szType` **\);**<br /><br /> Registra o script contido no recurso do módulo.*resFileName* indica o caminho UNC para o próprio módulo.*szID* e `szType` contêm o identificador de cadeia de caracteres do recurso e o tipo, respectivamente.|  
|**ResourceUnregisterSz**|**HRESULT ResourceUnregisterSz \(LPCOLESTR**  *resFileName* **, LPCOLESTR**  *szID* **, LPCOLESTR**  `szType` **\);**<br /><br /> Cancela o script contido no recurso do módulo.*resFileName* indica o caminho UNC para o próprio módulo.*szID* e `szType` contêm o identificador de cadeia de caracteres do recurso e o tipo, respectivamente.|  
|**FileRegister**|**HRESULT FileRegister \(LPCOLESTR**  *nome de arquivo*  **\);**<br /><br /> Registra o script em um arquivo.*fileName* é um caminho UNC para um arquivo que contém um script de recurso \(ou é uma\).|  
|**FileUnregister**|**HRESULT FileUnregister \(LPCOLESTR**  *nome de arquivo*  **\);**<br /><br /> Cancela o registro do script em um arquivo.*fileName* é um caminho UNC para um arquivo que contém um script de recurso \(ou é uma\).|  
|**StringRegister**|**HRESULT StringRegister \(LPCOLESTR**  *dados*  **\);**<br /><br /> Registra o script em uma cadeia de caracteres.*dados* contém o script propriamente dito.|  
|**StringUnregister**|**HRESULT StringUnregister \(LPCOLESTR**  *dados*  **\);**<br /><br /> Cancela o registro de script em uma cadeia de caracteres.*dados* contém o script propriamente dito.|  
  
 **ResourceRegisterSz** e **ResourceUnregisterSz**, são semelhantes às **ResourceRegister** e **ResourceUnregister**, mas permitem que você especifique um identificador de cadeia de caracteres.  
  
 Os métodos **FileRegister** e **FileUnregister** são úteis se você não quiser que o script em um recurso, ou se você quiser que o script em seu próprio arquivo. Os métodos **StringRegister** e **StringUnregister** permite que o arquivo. rgs sejam armazenados em uma cadeia de caracteres alocada dinamicamente.  
  
## Consulte também  
 [Criando scripts de escrivão](../Topic/Creating%20Registrar%20Scripts.md)