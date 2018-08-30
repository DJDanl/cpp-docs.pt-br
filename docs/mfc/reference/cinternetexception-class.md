---
title: Classe CInternetException | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CInternetException
- AFXINET/CInternetException
- AFXINET/CInternetException::CInternetException
- AFXINET/CInternetException::m_dwContext
- AFXINET/CInternetException::m_dwError
dev_langs:
- C++
helpviewer_keywords:
- CInternetException [MFC], CInternetException
- CInternetException [MFC], m_dwContext
- CInternetException [MFC], m_dwError
ms.assetid: 44fb3cbe-523e-4754-8843-a77909990b14
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f1439fc2a5d49a775f55c7c25e45f4faa9b9c99f
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43211271"
---
# <a name="cinternetexception-class"></a>Classe CInternetException
Representa uma condição de exceção relacionada a uma operação de Internet.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CInternetException : public CException  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInternetException::CInternetException](#cinternetexception)|Constrói um objeto `CInternetException`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInternetException::m_dwContext](#m_dwcontext)|O valor de contexto associado à operação que causou a exceção.|  
|[CInternetException::m_dwError](#m_dwerror)|O erro que causou a exceção.|  
  
## <a name="remarks"></a>Comentários  
 O `CInternetException` classe inclui dois membros de dados públicos: um contém o código de erro associado à exceção, e o outro contém o identificador de contexto do aplicativo da Internet associado com o erro.  
  
 Para obter mais informações sobre os identificadores de contexto para aplicativos da Internet, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 `CInternetException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxinet.h  
  
##  <a name="cinternetexception"></a>  CInternetException::CInternetException  
 Essa função membro é chamada quando um `CInternetException` objeto é criado.  
  
```  
CInternetException(DWORD dwError);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwError*  
 O erro que causou a exceção.  
  
### <a name="remarks"></a>Comentários  
 Para lançar um CInternetException, chame a função global do MFC [AfxThrowInternetException](internet-url-parsing-globals.md#afxthrowinternetexception).  
  
##  <a name="m_dwcontext"></a>  CInternetException::m_dwContext  
 O valor de contexto associado à operação da Internet relacionada.  
  
```  
DWORD_PTR m_dwContext;  
```  
  
### <a name="remarks"></a>Comentários  
 O identificador de contexto é especificado originalmente no [CInternetSession](../../mfc/reference/cinternetsession-class.md) e passado pelo MFC para [CInternetConnection](../../mfc/reference/cinternetconnection-class.md)- e [CInternetFile](../../mfc/reference/cinternetfile-class.md)-as classes derivadas. Você pode substituir esse padrão e atribuir qualquer *dwContext* parâmetro um valor de sua escolha. *dwContext* está associado a qualquer operação do objeto especificado. *dwContext* identifica as informações de status da operação retornadas por [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback).  
  
##  <a name="m_dwerror"></a>  CInternetException::m_dwError  
 O erro que causou a exceção.  
  
```  
DWORD m_dwError;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse valor de erro pode ser um sistema de código de erro, encontrado em WINERROR. H ou um valor de erro do WININET. H.  
  
 Para obter uma lista dos códigos de erro do Win32, consulte [códigos de erro](/windows/desktop/Debug/system-error-codes). Para obter uma lista das mensagens de erro específicas da Internet, consulte. Os dois tópicos são no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CException](../../mfc/reference/cexception-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CException](../../mfc/reference/cexception-class.md)
