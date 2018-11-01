---
title: Invocando Scripts (ATL)
ms.date: 11/04/2016
f1_keywords:
- StringRegister
helpviewer_keywords:
- StringRegister method
- scripts, invoking registry in ATL
ms.assetid: eabd41ee-586b-4266-9e92-5aaad04b73a4
ms.openlocfilehash: 170eb4c29571fcec8797727f54630894c9198442
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50650545"
---
# <a name="invoking-scripts"></a>Invocando Scripts

[Usando parâmetros substituíveis (pré-processador do registrador The)](../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md) discute os mapas de substituição e menciona o método de registrador **AddReplacement**. O registrador tem oito outros métodos específicos para a criação de scripts e todas são descritas na tabela a seguir.

|Método|Descrição da sintaxe /|
|------------|-------------------------|
|**ResourceRegister**|**HRESULT ResourceRegister (LPCOLESTR***resFileName* **, UINT** `nID` **, LPCOLESTR** `szType` **);**<br /><br /> Registra o script contido no recurso de um módulo. *resFileName* indica o caminho UNC para o próprio módulo. *nID* e *szType* contêm a ID do recurso e o tipo, respectivamente.|
|**ResourceUnregister**|**HRESULT ResourceUnregister (LPCOLESTR***resFileName* **, UINT** `nID` **, LPCOLESTR** `szType` **);**<br /><br /> Cancela o registro o script contido no recurso de um módulo. *resFileName* indica o caminho UNC para o próprio módulo. *nID* e *szType* contêm a ID do recurso e o tipo, respectivamente.|
|**ResourceRegisterSz**|**HRESULT ResourceRegisterSz (LPCOLESTR***resFileName* **, LPCOLESTR***szID* **, LPCOLESTR** `szType` **);**<br /><br /> Registra o script contido no recurso de um módulo. *resFileName* indica o caminho UNC para o próprio módulo. *szID* e *szType* contêm o tipo e o identificador de cadeia de caracteres do recurso, respectivamente.|
|**ResourceUnregisterSz**|**HRESULT ResourceUnregisterSz (LPCOLESTR***resFileName* **, LPCOLESTR***szID* **, LPCOLESTR** `szType` **);**<br /><br /> Cancela o registro o script contido no recurso de um módulo. *resFileName* indica o caminho UNC para o próprio módulo. *szID* e *szType* contêm o tipo e o identificador de cadeia de caracteres do recurso, respectivamente.|
|**FileRegister**|**HRESULT FileRegister (LPCOLESTR***fileName***);**<br /><br /> Registra o script em um arquivo. *nome do arquivo* é um caminho UNC para um arquivo que contém um script de recurso (ou é uma).|
|**FileUnregister**|**HRESULT FileUnregister (LPCOLESTR***fileName***);**<br /><br /> Cancela o registro o script em um arquivo. *nome do arquivo* é um caminho UNC para um arquivo que contém um script de recurso (ou é uma).|
|**StringRegister**|**HRESULT StringRegister (LPCOLESTR***dados***);**<br /><br /> Registra o script em uma cadeia de caracteres. *dados* contém o script propriamente dito.|
|**StringUnregister**|**HRESULT StringUnregister (LPCOLESTR***dados***);**<br /><br /> Cancela o registro de script em uma cadeia de caracteres. *dados* contém o script propriamente dito.|

**ResourceRegisterSz** e **ResourceUnregisterSz**, são semelhantes às **ResourceRegister** e **ResourceUnregister**, mas permitem que você especifique uma cadeia de caracteres identificador.

Os métodos **FileRegister** e **FileUnregister** são úteis se você não quiser que o script em um recurso ou se você quiser que o script em seu próprio arquivo. Os métodos **StringRegister** e **StringUnregister** permite que o arquivo. rgs sejam armazenados em uma cadeia de caracteres dinamicamente alocada.

## <a name="see-also"></a>Consulte também

[Criando scripts do Registrador](../atl/creating-registrar-scripts.md)

