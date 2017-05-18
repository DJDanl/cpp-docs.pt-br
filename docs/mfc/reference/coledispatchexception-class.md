---
title: Classe COleDispatchException | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
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
- COleDispatchException class
- Automation, exceptions
- exceptions, OLE
- OLE exceptions, to IDispatch interface
ms.assetid: 0e95c8be-e21a-490c-99ec-181c6a9a26d0
caps.latest.revision: 22
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 0071e57b6c8f6bec73712186e8ff8baa9bfcc165
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="coledispatchexception-class"></a>Classe COleDispatchException
Lida com exceções específicas para o OLE `IDispatch` interface, que é uma parte fundamental de automação OLE.  
  
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
|[COleDispatchException::m_strHelpFile](#m_strhelpfile)|Para usar com o arquivo de Ajuda `m_dwHelpContext`.|  
|[COleDispatchException::m_strSource](#m_strsource)|Aplicativo que gerou a exceção.|  
|[COleDispatchException::m_wCode](#m_wcode)|`IDispatch`-código de erro específico.|  
  
## <a name="remarks"></a>Comentários  
 Como as outras classes de exceção derivam o `CException` classe base `COleDispatchException` pode ser usado com o **lançar**, `THROW_LAST`, **tente**, **CATCH**, `AND_CATCH`, e `END_CATCH` macros.  
  
 Em geral, você deve chamar [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) para criar e lançar uma `COleDispatchException` objeto.  
  
 Para obter mais informações sobre exceções, consulte os artigos [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md) e [exceções: exceções OLE](../../mfc/exceptions-ole-exceptions.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 `COleDispatchException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
##  <a name="m_dwhelpcontext"></a>COleDispatchException::m_dwHelpContext  
 Identifica um contexto de ajuda na Ajuda do aplicativo (. Arquivo HLP).  
  
```  
DWORD m_dwHelpContext;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse membro é definido pela função [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) quando uma exceção é lançada.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [COleDispatchDriver::CreateDispatch](../../mfc/reference/coledispatchdriver-class.md#createdispatch).  
  
##  <a name="m_strdescription"></a>COleDispatchException::m_strDescription  
 Contém uma descrição textual do erro, como "Disco cheio".  
  
```  
CString m_strDescription;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse membro é definido pela função [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) quando uma exceção é lançada.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [COleDispatchDriver::CreateDispatch](../../mfc/reference/coledispatchdriver-class.md#createdispatch).  
  
##  <a name="m_strhelpfile"></a>COleDispatchException::m_strHelpFile  
 O framework preenche essa cadeia de caracteres com o nome do arquivo de Ajuda do aplicativo.  
  
```  
CString m_strHelpFile;  
```  
  
##  <a name="m_strsource"></a>COleDispatchException::m_strSource  
 O framework preenche essa cadeia de caracteres com o nome do aplicativo que gerou a exceção.  
  
```  
CString m_strSource;  
```  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [COleDispatchDriver::CreateDispatch](../../mfc/reference/coledispatchdriver-class.md#createdispatch).  
  
##  <a name="m_wcode"></a>COleDispatchException::m_wCode  
 Contém um código de erro específico para seu aplicativo.  
  
```  
WORD m_wCode;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse membro é definido pela função [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) quando uma exceção é lançada.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CALCDRIV](../../visual-cpp-samples.md)   
 [Classe CException](../../mfc/reference/cexception-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDispatchDriver](../../mfc/reference/coledispatchdriver-class.md)   
 [Classe COleException](../../mfc/reference/coleexception-class.md)

