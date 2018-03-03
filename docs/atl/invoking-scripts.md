---
title: Invocar Scripts (ATL) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- StringRegister
dev_langs:
- C++
helpviewer_keywords:
- StringRegister method
- scripts, invoking registry in ATL
ms.assetid: eabd41ee-586b-4266-9e92-5aaad04b73a4
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7cbf969f601bd90e84bf0ee15ae2ea3dcb392610
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="invoking-scripts"></a>Invocar Scripts
[Usando parâmetros substituíveis (do registrador pré-processador)](../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md) discute mapas de substituição e menciona o método do registrador **AddReplacement**. O registrador tem oito outros métodos específicos para scripts e todas são descritas na tabela a seguir.  
  
|Método|Descrição da sintaxe /|  
|------------|-------------------------|  
|**ResourceRegister**|**HRESULT ResourceRegister (LPCOLESTR***resFileName* **, UINT** `nID` **, LPCOLESTR** `szType` **);** <br /><br /> Registra o script contido no recurso do módulo. *resFileName* indica o caminho UNC para o próprio módulo. `nID`e `szType` contém a ID do recurso e o tipo, respectivamente.|  
|**ResourceUnregister**|**HRESULT ResourceUnregister (LPCOLESTR***resFileName* **, UINT** `nID` **, LPCOLESTR** `szType` **);** <br /><br /> Cancela o registro o script contido no recurso do módulo. *resFileName* indica o caminho UNC para o próprio módulo. `nID`e `szType` contém a ID do recurso e o tipo, respectivamente.|  
|**ResourceRegisterSz**|**HRESULT ResourceRegisterSz (LPCOLESTR***resFileName* **, LPCOLESTR***szID* **, LPCOLESTR** `szType` **);** <br /><br /> Registra o script contido no recurso do módulo. *resFileName* indica o caminho UNC para o próprio módulo. *szID* e `szType` contém o identificador de cadeia de caracteres do recurso e o tipo, respectivamente.|  
|**ResourceUnregisterSz**|**HRESULT ResourceUnregisterSz (LPCOLESTR***resFileName* **, LPCOLESTR***szID* **, LPCOLESTR** `szType` **);** <br /><br /> Cancela o registro o script contido no recurso do módulo. *resFileName* indica o caminho UNC para o próprio módulo. *szID* e `szType` contém o identificador de cadeia de caracteres do recurso e o tipo, respectivamente.|  
|**FileRegister**|**HRESULT FileRegister (LPCOLESTR***fileName***);** <br /><br /> Registra o script em um arquivo. *nome de arquivo* é um caminho UNC para um arquivo que contém um script de recurso (ou é uma).|  
|**FileUnregister**|**HRESULT FileUnregister (LPCOLESTR***fileName***);** <br /><br /> Cancela o registro de script em um arquivo. *nome de arquivo* é um caminho UNC para um arquivo que contém um script de recurso (ou é uma).|  
|**StringRegister**|**HRESULT StringRegister (LPCOLESTR***dados***);** <br /><br /> Registra o script em uma cadeia de caracteres. *dados* contém o script propriamente dito.|  
|**StringUnregister**|**HRESULT StringUnregister (LPCOLESTR***dados***);** <br /><br /> Cancela o registro de script em uma cadeia de caracteres. *dados* contém o script propriamente dito.|  
  
 **ResourceRegisterSz** e **ResourceUnregisterSz**, são semelhantes às **ResourceRegister** e **ResourceUnregister**, mas permitem que você especifique um Identificador de cadeia de caracteres.  
  
 Os métodos **FileRegister** e **FileUnregister** são úteis se você não quiser que o script em um recurso, ou se você quiser que o script em seu próprio arquivo. Os métodos **StringRegister** e **StringUnregister** permite que o arquivo. rgs a ser armazenado em uma cadeia de caracteres alocada dinamicamente.  
  
## <a name="see-also"></a>Consulte também  
 [Criando scripts do Registrador](../atl/creating-registrar-scripts.md)

