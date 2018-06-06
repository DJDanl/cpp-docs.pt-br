---
title: Classe FtmBase | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- ftm/Microsoft::WRL::FtmBase
dev_langs:
- C++
helpviewer_keywords:
- FtmBase class
ms.assetid: 275f3b71-2975-4f92-89e7-d351e96496df
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 38f30c497fc8640b1f88f4ffb3fc6f14bed55a3e
ms.sourcegitcommit: e3b4ef19b534a2ed48bb9091e5197a6e536f16c1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/06/2018
ms.locfileid: "34814346"
---
# <a name="ftmbase-class"></a>Classe FtmBase
Representa um objeto de empacotamento de segmentação livre.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
class FtmBase : public Microsoft::WRL::Implements<  
   Microsoft::WRL::RuntimeClassFlags<WinRtClassicComMix>,   
   Microsoft::WRL::CloakedIid<IMarshal> >;  
```  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [classe RuntimeClass](runtimeclass-class.md).  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor FtmBase::FtmBase](../windows/ftmbase-ftmbase-constructor.md)|Inicializa uma nova instância da classe FtmBase.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método FtmBase::CreateGlobalInterfaceTable](../windows/ftmbase-createglobalinterfacetable-method.md)|Cria uma tabela de interface global (GIT).|  
|[Método FtmBase::DisconnectObject](../windows/ftmbase-disconnectobject-method.md)|Forçar libera todas as conexões externas para um objeto. Servidor do objeto chama a implementação do objeto do método antes de desligar.|  
|[Método FtmBase::GetMarshalSizeMax](../windows/ftmbase-getmarshalsizemax-method.md)|Obter o limite superior no número de bytes necessários para realizar marshaling do ponteiro de interface especificado no objeto especificado.|  
|[Método FtmBase::GetUnmarshalClass](../windows/ftmbase-getunmarshalclass-method.md)|Obtém o CLSID COM usa para localizar a DLL que contém o código para o proxy correspondente. COM carrega dessa DLL para criar uma instância não inicializada do proxy.|  
|[Método FtmBase::MarshalInterface](../windows/ftmbase-marshalinterface-method.md)|Grava em um fluxo de dados necessários para inicializar um objeto de proxy em algum processo do cliente.|  
|[Método FtmBase::ReleaseMarshalData](../windows/ftmbase-releasemarshaldata-method.md)|Destrói um pacote de dados empacotado.|  
|[Método FtmBase::UnmarshalInterface](../windows/ftmbase-unmarshalinterface-method.md)|Inicializa um proxy criado recentemente e retorna um ponteiro de interface de proxy.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados FtmBase::marshaller_](../windows/ftmbase-marshaller-data-member.md)|Contém uma referência para o marshaler livre de threads.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `FtmBase`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ftm.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)