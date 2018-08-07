---
title: Classe HString | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HString
dev_langs:
- C++
ms.assetid: 6709dd2e-8d72-4675-8ec7-1baa7d71854d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 868d0a4e2d84add447c95bfcd9690c8a17850718
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39571445"
---
# <a name="hstring-class"></a>Classe HString
Uma classe auxiliar para gerenciar o tempo de vida de um HSTRING usando o padrão RAII.
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
class HString;  
```  
  
## <a name="remarks"></a>Comentários  
 O tempo de execução do Windows fornece acesso às cadeias de caracteres através das alças HSTRING. O **HString** classe fornece funções de conveniência e operadores para simplificar o uso de identificadores de HSTRING. Essa classe pode manipular o tempo de vida do HSTRING ela detém por meio de um padrão RAII. 
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor HString::HString](../windows/hstring-hstring-constructor.md)|Inicializa uma nova instância dos **HString** classe.|  
|[Destruidor HString::~HString](../windows/hstring-tilde-hstring-destructor.md)|Destrói a instância atual do **HString** classe.|  
  
### <a name="members"></a>Membros  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método HString::Set](../windows/hstring-set-method.md)|Define o valor do atual **HString** objeto de cadeia de caracteres largos especificada ou **HString** parâmetro.|  
|[Método HString::Attach](../windows/hstring-attach-method.md)|Associa a especificada **HString** objeto com o atual **HString** objeto.|  
|[Método HString::CopyTo](../windows/hstring-copyto-method.md)|Copia o atual **HString** objeto para um objeto HSTRING.|  
|[Método HString::Detach](../windows/hstring-detach-method.md)|Desassocia especificado **HString** objeto do valor subjacente.|  
|[Método HString::GetAddressOf](../windows/hstring-getaddressof-method.md)|Recupera um ponteiro para o identificador subjacente de HSTRING.|  
|[Método HString::Get](../windows/hstring-get-method.md)|Recupera o valor do identificador subjacente de HSTRING.|  
|[Método HString::Release](../windows/hstring-release-method.md)|Exclui o valor de cadeia de caracteres subjacente e inicializa o atual **HString** objeto para um valor vazio.|  
|[Método HString::MakeReference](../windows/hstring-makereference-method.md)|Cria um `HStringReference` objeto a partir de um parâmetro de cadeia de caracteres especificada.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador HString::Operator=](../windows/hstring-operator-assign-operator.md)|Move o valor de outro **HString** objeto atual **HString** objeto.|  
|[Operador HString::Operator==](../windows/hstring-operator-equality-operator.md)|Indica se os dois parâmetros são iguais.|  
|[Operador HString::Operator!=](../windows/hstring-operator-inequality-operator.md)|Indica se os dois parâmetros não são iguais.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `HString`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)