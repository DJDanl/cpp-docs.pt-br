---
title: Classe COleException | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleException
- AFXDISP/COleException
- AFXDISP/COleException::Process
- AFXDISP/COleException::m_sc
dev_langs:
- C++
helpviewer_keywords:
- COleException [MFC], Process
- COleException [MFC], m_sc
ms.assetid: 2571e9fe-26cc-42f0-9ad9-8ad5b4311ec1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7a472de31695ab6038cab9ba0158580f3d305194
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43212482"
---
# <a name="coleexception-class"></a>Classe COleException
Representa uma condição de exceção relacionada a uma operação OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleException : public CException  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleException::Process](#process)|Converte uma exceção capturada em um código de retorno OLE.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleException::m_sc](#m_sc)|Contém o código de status que indica o motivo da exceção.|  
  
## <a name="remarks"></a>Comentários  
 O `COleException` classe inclui um membro de dados pública que contém o código de status que indica o motivo da exceção.  
  
 Em geral, você não deve criar uma `COleException` do objeto diretamente; em vez disso, você deve chamar [AfxThrowOleException](exception-processing.md#afxthrowoleexception).  
  
 Para obter mais informações sobre exceções, consulte os artigos [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md) e [exceções: exceções OLE](../../mfc/exceptions-ole-exceptions.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 `COleException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
##  <a name="m_sc"></a>  COleException::m_sc  
 Este membro de dados contém o código de status OLE que indica o motivo da exceção.  
  
```  
SCODE m_sc;  
```  
  
### <a name="remarks"></a>Comentários  
 O valor da variável é definido por [AfxThrowOleException](exception-processing.md#afxthrowoleexception).  
  
 Para obter mais informações sobre SCODE, consulte [estrutura de códigos de erro COM](/windows/desktop/com/structure-of-com-error-codes) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer#22](../../mfc/codesnippet/cpp/coleexception-class_1.cpp)]  
  
##  <a name="process"></a>  COleException::Process  
 Chame o **processo** função de membro para converter uma exceção capturada em um código de status OLE.  
  
```  
static SCODE PASCAL Process(const CException* pAnyException);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pAnyException*  
 Ponteiro para uma exceção capturada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um código de status OLE.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Essa função é **estático**.  
  
 Para obter mais informações sobre SCODE, consulte [estrutura de códigos de erro COM](/windows/desktop/com/structure-of-com-error-codes) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [COleDispatchDriver::CreateDispatch](../../mfc/reference/coledispatchdriver-class.md#createdispatch).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CALCDRIV](../../visual-cpp-samples.md)   
 [Classe CException](../../mfc/reference/cexception-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



