---
title: Classe COleDispatchException | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleDispatchException
- AFXDISP/COleDispatchException
- AFXDISP/COleDispatchException::m_dwHelpContext
- AFXDISP/COleDispatchException::m_strDescription
- AFXDISP/COleDispatchException::m_strHelpFile
- AFXDISP/COleDispatchException::m_strSource
- AFXDISP/COleDispatchException::m_wCode
dev_langs:
- C++
helpviewer_keywords:
- COleDispatchException [MFC], m_dwHelpContext
- COleDispatchException [MFC], m_strDescription
- COleDispatchException [MFC], m_strHelpFile
- COleDispatchException [MFC], m_strSource
- COleDispatchException [MFC], m_wCode
ms.assetid: 0e95c8be-e21a-490c-99ec-181c6a9a26d0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 65e7c613f5c4a4273208e30cd0fc6284ef4e420c
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37037864"
---
# <a name="coledispatchexception-class"></a>Classe COleDispatchException
Manipula exceções específicas para o OLE `IDispatch` interface, que é uma parte importante da automação OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleDispatchException : public CException  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDispatchException::m_dwHelpContext](#m_dwhelpcontext)|Contexto de ajuda para o erro.|  
|[COleDispatchException::m_strDescription](#m_strdescription)|Descrição textual do erro.|  
|[COleDispatchException::m_strHelpFile](#m_strhelpfile)|Ajuda do arquivo a ser usado com `m_dwHelpContext`.|  
|[COleDispatchException::m_strSource](#m_strsource)|Aplicativo que gerou a exceção.|  
|[COleDispatchException::m_wCode](#m_wcode)|`IDispatch`-código de erro específico.|  
  
## <a name="remarks"></a>Comentários  
 Como as outras classes de exceção derivado de `CException` classe base `COleDispatchException` pode ser usado com as macros THROW, THROW_LAST, TRY, CATCH, AND_CATCH e END_CATCH.  
  
 Em geral, você deve chamar [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) para criar e lançar um `COleDispatchException` objeto.  
  
 Para obter mais informações sobre exceções, consulte os artigos [de tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md) e [exceções: exceções OLE](../../mfc/exceptions-ole-exceptions.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 `COleDispatchException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
##  <a name="m_dwhelpcontext"></a>  COleDispatchException::m_dwHelpContext  
 Identifica um contexto de ajuda na Ajuda do aplicativo (. Arquivo HLP).  
  
```  
DWORD m_dwHelpContext;  
```  
  
### <a name="remarks"></a>Comentários  
 Este membro é definido pela função [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) quando uma exceção será lançada.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [COleDispatchDriver::CreateDispatch](../../mfc/reference/coledispatchdriver-class.md#createdispatch).  
  
##  <a name="m_strdescription"></a>  COleDispatchException::m_strDescription  
 Contém uma descrição textual do erro, como "Disco cheio".  
  
```  
CString m_strDescription;  
```  
  
### <a name="remarks"></a>Comentários  
 Este membro é definido pela função [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) quando uma exceção será lançada.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [COleDispatchDriver::CreateDispatch](../../mfc/reference/coledispatchdriver-class.md#createdispatch).  
  
##  <a name="m_strhelpfile"></a>  COleDispatchException::m_strHelpFile  
 A estrutura preenche essa cadeia de caracteres com o nome do arquivo de Ajuda do aplicativo.  
  
```  
CString m_strHelpFile;  
```  
  
##  <a name="m_strsource"></a>  COleDispatchException::m_strSource  
 A estrutura preenche essa cadeia de caracteres com o nome do aplicativo que gerou a exceção.  
  
```  
CString m_strSource;  
```  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [COleDispatchDriver::CreateDispatch](../../mfc/reference/coledispatchdriver-class.md#createdispatch).  
  
##  <a name="m_wcode"></a>  COleDispatchException::m_wCode  
 Contém um código de erro específico para seu aplicativo.  
  
```  
WORD m_wCode;  
```  
  
### <a name="remarks"></a>Comentários  
 Este membro é definido pela função [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) quando uma exceção será lançada.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CALCDRIV](../../visual-cpp-samples.md)   
 [Classe CException](../../mfc/reference/cexception-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDispatchDriver](../../mfc/reference/coledispatchdriver-class.md)   
 [Classe COleException](../../mfc/reference/coleexception-class.md)
