---
title: Classe CSyncObject | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CSyncObject
- AFXMT/CSyncObject
- AFXMT/CSyncObject::CSyncObject
- AFXMT/CSyncObject::Lock
- AFXMT/CSyncObject::Unlock
- AFXMT/CSyncObject::m_hObject
dev_langs:
- C++
helpviewer_keywords:
- CSyncObject [MFC], CSyncObject
- CSyncObject [MFC], Lock
- CSyncObject [MFC], Unlock
- CSyncObject [MFC], m_hObject
ms.assetid: c62ea6eb-a17b-4e01-aed4-321fc435a5f4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bcc5290b08b6a0b6159c1ba9b0b5b05d02a178ba
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37122063"
---
# <a name="csyncobject-class"></a>Classe CSyncObject
Uma classe virtual pura que fornece funcionalidade comum para os objetos de sincronização no Win32.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSyncObject : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSyncObject::CSyncObject](#csyncobject)|Constrói um objeto `CSyncObject`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSyncObject::Lock](#lock)|Obtiver acesso ao objeto de sincronização.|  
|[CSyncObject::Unlock](#unlock)|Obtiver acesso ao objeto de sincronização.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Identificador de CSyncObject::operator](#operator_handle)|Fornece acesso ao objeto de sincronização.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSyncObject::m_hObject](#m_hobject)|O identificador para o objeto de sincronização.|  
  
## <a name="remarks"></a>Comentários  
 A biblioteca Microsoft Foundation Class fornece várias classes derivadas de `CSyncObject`. Esses são [CEvent](../../mfc/reference/cevent-class.md), [CMutex](../../mfc/reference/cmutex-class.md), [CCriticalSection](../../mfc/reference/ccriticalsection-class.md), e [CSemaphore](../../mfc/reference/csemaphore-class.md).  
  
 Para obter informações sobre como usar os objetos de sincronização, consulte o artigo [Multithreading: como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CSyncObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmt.h  
  
##  <a name="csyncobject"></a>  CSyncObject::CSyncObject  
 Constrói um objeto de sincronização com o nome fornecido.  
  
```  
explicit CSyncObject(LPCTSTR pstrName);  
virtual ~CSyncObject();
```  
  
### <a name="parameters"></a>Parâmetros  
 *pstrName*  
 O nome do objeto. Se for NULL, *pstrName* será nulo.  
  
##  <a name="lock"></a>  CSyncObject::Lock  
 Chame essa função para acessar o recurso controlado pelo objeto de sincronização.  
  
```  
virtual BOOL Lock(DWORD dwTimeout = INFINITE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwTimeout*  
 Especifica a quantidade de tempo em milissegundos de espera para o objeto de sincronização esteja disponível (sinalizado). Se for infinito, `Lock` aguardará até que o objeto é sinalizado antes de retornar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o objeto de sincronização foi sinalizado, `Lock` retornará com êxito e o thread agora possui o objeto. Se o objeto de sincronização for não sinalizado (não disponível) `Lock` aguardará para o objeto de sincronização ficar sinalizado até o número de milissegundos especificado no *dwTimeOut* parâmetro. Se o objeto de sincronização não tornou-se sinalizado na quantidade especificada de tempo, `Lock` retorna falha.  
  
##  <a name="m_hobject"></a>  CSyncObject::m_hObject  
 O identificador para o objeto de sincronização.  
  
```  
HANDLE m_hObject;  
```  
  
##  <a name="operator_handle"></a>  Identificador de CSyncObject::operator  
 Use este operador para obter o identificador do `CSyncObject` objeto.  
  
```  
operator HANDLE() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o identificador do objeto de sincronização; Caso contrário, nulo.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar o identificador para chamar diretamente as APIs do Windows.  
  
##  <a name="unlock"></a>  CSyncObject::Unlock  
 A declaração de `Unlock` sem parâmetros é uma função virtual pura e deve ser substituído por todas as classes derivadas de `CSyncObject`.  
  
```  
virtual BOOL Unlock() = 0; virtual BOOL Unlock(
    LONG lCount,  
    LPLONG lpPrevCount = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lCount*  
 Não usado pela implementação do padrão.  
  
 *lpPrevCount*  
 Não usado pela implementação do padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 Implementação do padrão sempre retorna TRUE.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão de declaração com dois parâmetros sempre retorna TRUE. Essa função é chamada para liberar o acesso para o objeto de sincronização de thread de chamada de propriedade. A segunda declaração é fornecida para objetos de sincronização como semáforos que permitem a mais de um acesso de um recurso controlado.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



