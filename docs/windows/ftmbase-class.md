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
ms.openlocfilehash: ed3e9b9e66f673a3d86ded7b3d576e1203db9595
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39570555"
---
# <a name="ftmbase-class"></a>Classe FtmBase
Representa um objeto livre de marshaler.  
  
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
|[Construtor FtmBase::FtmBase](../windows/ftmbase-ftmbase-constructor.md)|Inicializa uma nova instância dos **FtmBase** classe.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método FtmBase::CreateGlobalInterfaceTable](../windows/ftmbase-createglobalinterfacetable-method.md)|Cria uma tabela de interface global (GIT).|  
|[Método FtmBase::DisconnectObject](../windows/ftmbase-disconnectobject-method.md)|Libera forçadamente todas as conexões externas para um objeto. Servidor do objeto chama a implementação do objeto desse método antes de desligar.|  
|[Método FtmBase::GetMarshalSizeMax](../windows/ftmbase-getmarshalsizemax-method.md)|Obtenha o limite superior no número de bytes necessários para realizar marshaling do ponteiro de interface especificado no objeto especificado.|  
|[Método FtmBase::GetUnmarshalClass](../windows/ftmbase-getunmarshalclass-method.md)|Obtém o CLSID que COM usa para localizar a DLL que contém o código para o proxy correspondente. COM carrega essa DLL para criar uma instância não inicializada do proxy.|  
|[Método FtmBase::MarshalInterface](../windows/ftmbase-marshalinterface-method.md)|Grava os dados necessários para inicializar um objeto de proxy em algum processo do cliente em um fluxo.|  
|[Método FtmBase::ReleaseMarshalData](../windows/ftmbase-releasemarshaldata-method.md)|Destrói um pacote de dados com marshaling.|  
|[Método FtmBase::UnmarshalInterface](../windows/ftmbase-unmarshalinterface-method.md)|Inicializa um proxy recém-criado e retorna um ponteiro de interface para esse proxy.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados FtmBase::marshaller_](../windows/ftmbase-marshaller-data-member.md)|Contém uma referência para o marshaler livre.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `FtmBase`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ftm.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)