---
title: Invocar Scripts (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
f1_keywords:
- StringRegister
dev_langs:
- C++
helpviewer_keywords:
- StringRegister method
- scripts, invoking registry in ATL
ms.assetid: eabd41ee-586b-4266-9e92-5aaad04b73a4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 91d11b86b2b7cf17ef90ab701b06c6f31b272691
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="invoking-scripts"></a>Invocar Scripts
[Usando parâmetros substituíveis (do registrador pré-processador)](../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md) discute mapas de substituição e menciona o método do registrador **AddReplacement**. O registrador tem oito outros métodos específicos para scripts e todas são descritas na tabela a seguir.  
  
|Método|Descrição da sintaxe /|  
|------------|-------------------------|  
|**ResourceRegister**|**HRESULT ResourceRegister (LPCOLESTR***resFileName* **, UINT** `nID` **, LPCOLESTR** `szType` **);** <br /><br /> Registra o script contido no recurso do módulo. *resFileName* indica o caminho UNC para o próprio módulo. `nID` e `szType` contém a ID do recurso e o tipo, respectivamente.|  
|**ResourceUnregister**|**HRESULT ResourceUnregister (LPCOLESTR***resFileName* **, UINT** `nID` **, LPCOLESTR** `szType` **);** <br /><br /> Cancela o registro o script contido no recurso do módulo. *resFileName* indica o caminho UNC para o próprio módulo. `nID` e `szType` contém a ID do recurso e o tipo, respectivamente.|  
|**ResourceRegisterSz**|**HRESULT ResourceRegisterSz (LPCOLESTR***resFileName* **, LPCOLESTR***szID* **, LPCOLESTR** `szType` **);** <br /><br /> Registra o script contido no recurso do módulo. *resFileName* indica o caminho UNC para o próprio módulo. *szID* e `szType` contém o identificador de cadeia de caracteres do recurso e o tipo, respectivamente.|  
|**ResourceUnregisterSz**|**HRESULT ResourceUnregisterSz (LPCOLESTR***resFileName* **, LPCOLESTR***szID* **, LPCOLESTR** `szType` **);** <br /><br /> Cancela o registro o script contido no recurso do módulo. *resFileName* indica o caminho UNC para o próprio módulo. *szID* e `szType` contém o identificador de cadeia de caracteres do recurso e o tipo, respectivamente.|  
|**FileRegister**|**HRESULT FileRegister (LPCOLESTR***fileName***);** <br /><br /> Registra o script em um arquivo. *nome de arquivo* é um caminho UNC para um arquivo que contém um script de recurso (ou é uma).|  
|**FileUnregister**|**HRESULT FileUnregister (LPCOLESTR***fileName***);** <br /><br /> Cancela o registro de script em um arquivo. *nome de arquivo* é um caminho UNC para um arquivo que contém um script de recurso (ou é uma).|  
|**StringRegister**|**HRESULT StringRegister (LPCOLESTR***dados***);** <br /><br /> Registra o script em uma cadeia de caracteres. *dados* contém o script propriamente dito.|  
|**StringUnregister**|**HRESULT StringUnregister (LPCOLESTR***dados***);** <br /><br /> Cancela o registro de script em uma cadeia de caracteres. *dados* contém o script propriamente dito.|  
  
 **ResourceRegisterSz** e **ResourceUnregisterSz**, são semelhantes às **ResourceRegister** e **ResourceUnregister**, mas permitem que você especifique uma cadeia de caracteres identificador.  
  
 Os métodos **FileRegister** e **FileUnregister** são úteis se você não quiser que o script em um recurso, ou se você quiser que o script em seu próprio arquivo. Os métodos **StringRegister** e **StringUnregister** permite que o arquivo. rgs a ser armazenado em uma cadeia de caracteres alocada dinamicamente.  
  
## <a name="see-also"></a>Consulte também  
 [Criando scripts do Registrador](../atl/creating-registrar-scripts.md)

