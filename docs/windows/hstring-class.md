---
title: Classe HString | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HString
dev_langs:
- C++
ms.assetid: 6709dd2e-8d72-4675-8ec7-1baa7d71854d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3e8d66f134eef5f2ecb75b30fd68874418dbc49d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="hstring-class"></a>Classe HString
Uma classe auxiliar para gerenciar o tempo de vida de um HSTRING usando o padrão RAII.
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
class HString;  
```  
  
## <a name="remarks"></a>Comentários  
 O tempo de execução do Windows fornece acesso às cadeias de caracteres através de identificadores de HSTRING. A classe HString fornece funções de conveniência e operadores para simplificar o uso de identificadores HSTRING. Essa classe pode lidar com o tempo de vida do HSTRING tem por meio de um padrão RAII. 
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor HString::HString](../windows/hstring-hstring-constructor.md)|Inicializa uma nova instância da classe HString.|  
|[Destruidor HString::~HString](../windows/hstring-tilde-hstring-destructor.md)|Destrói a instância atual da classe HString.|  
  
### <a name="members"></a>Membros  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método HString::Set](../windows/hstring-set-method.md)|Define o valor do objeto HString atual para a cadeia de caracteres largos especificada ou o parâmetro de HString.|  
|[Método HString::Attach](../windows/hstring-attach-method.md)|Associa o objeto HString especificado com o objeto HString atual.|  
|[Método HString::CopyTo](../windows/hstring-copyto-method.md)|Copia o HString atual objeto para um objeto HSTRING.|  
|[Método HString::Detach](../windows/hstring-detach-method.md)|Desassocia o objeto HString especificado do valor subjacente.|  
|[Método HString::GetAddressOf](../windows/hstring-getaddressof-method.md)|Recupera um ponteiro para o identificador HSTRING subjacente.|  
|[Método HString::Get](../windows/hstring-get-method.md)|Recupera o valor do identificador HSTRING subjacente.|  
|[Método HString::Release](../windows/hstring-release-method.md)|Exclui o valor de cadeia de caracteres subjacente e inicializa o objeto HString atual para um valor vazio.|  
|[Método HString::MakeReference](../windows/hstring-makereference-method.md)|Cria um objeto HStringReference de um parâmetro de cadeia de caracteres especificada.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador HString::Operator=](../windows/hstring-operator-assign-operator.md)|Move o valor de outro objeto HString ao objeto HString atual.|  
|[Operador HString::Operator==](../windows/hstring-operator-equality-operator.md)|Indica se os dois parâmetros são iguais.|  
|[Operador HString::Operator!=](../windows/hstring-operator-inequality-operator.md)|Indica se os dois parâmetros não são iguais.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `HString`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)