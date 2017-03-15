---
title: Classe CSimpleException | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSimpleException
dev_langs:
- C++
helpviewer_keywords:
- CSimpleException class
ms.assetid: be0eb8ef-e5b9-47d6-b0fb-efaff2d1e666
caps.latest.revision: 19
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 5612d76a2351b9898b8ffe082844686d21fcd7a0
ms.lasthandoff: 02/25/2017

---
# <a name="csimpleexception-class"></a>Classe CSimpleException
Essa classe é uma classe base para exceções recursos críticos do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class AFX_NOVTABLE CSimpleException : public CException  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleException::CSimpleException](#csimpleexception)|O construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleException::GetErrorMessage](#geterrormessage)|Fornece o texto sobre o erro que ocorreu.|  
  
## <a name="remarks"></a>Comentários  
 `CSimpleException`é a classe base para exceções recursos críticos do MFC e lida com a propriedade e a inicialização de uma mensagem de erro. As seguintes classes usam `CSimpleException` como classe base:  
  
|||  
|-|-|  
|[Classe CMemoryException](../../mfc/reference/cmemoryexception-class.md)|Exceção de memória insuficiente|  
|[Classe CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md)|Solicitações para uma operação sem suporte|  
|[Classe CResourceException](../../mfc/reference/cresourceexception-class.md)|Recursos do Windows não foi encontrado ou não criáveis|  
|[Classe CUserException](../../mfc/reference/cuserexception-class.md)|Não foi possível encontrar uma exceção que indica um recurso|  
|[Classe CInvalidArgException](../../mfc/reference/cinvalidargexception-class.md)|Exceção que indica um argumento inválido|  
  
 Porque `CSimpleException` é uma classe base abstrata, você não pode declarar uma `CSimpleException` objeto diretamente. Em vez disso, você deve declarar objetos derivados, como aqueles na tabela anterior. Se você está declarando sua própria classe derivada, use as classes anteriores como um modelo.  
  
 Para obter mais informações, consulte o [classe CException](../../mfc/reference/cexception-class.md) tópico e [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 `CSimpleException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h  
  
##  <a name="a-namecsimpleexceptiona--csimpleexceptioncsimpleexception"></a><a name="csimpleexception"></a>CSimpleException::CSimpleException  
 O construtor.  
  
```  
CSimpleException();  
explicit CSimpleException(BOOL bAutoDelete);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bAutoDelete`  
 Especifique **TRUE** se a memória para a `CSimpleException` objeto foi alocado no heap. Isso fará com que o `CSimpleException` objeto a ser excluído quando o **excluir** função de membro é chamada para remover a exceção. Especifique **FALSE** se o `CSimpleException` objeto na pilha ou é um objeto global. Nesse caso, o `CSimpleException` objeto não será excluído quando o **excluir** é chamada de função de membro.  
  
### <a name="remarks"></a>Comentários  
 Você normalmente não precisa chamar esse construtor diretamente. Uma função que lança uma exceção deve criar uma instância de um `CException`-classe derivada e chama seu construtor, ou ele deve usar uma do MFC lançar funções, como [AfxThrowFileException](exception-processing.md#afxthrowfileexception), para gerar um tipo predefinido.  
  
##  <a name="a-namegeterrormessagea--csimpleexceptiongeterrormessage"></a><a name="geterrormessage"></a>CSimpleException::GetErrorMessage  
 Chame essa função de membro para fornecer um texto sobre o erro que ocorreu.  
  
```  
virtual BOOL GetErrorMessage(
    LPTSTR lpszError,
    UINT  nMaxError,
    PUNIT  pnHelpContext = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszError`  
 Um ponteiro para um buffer que receberá uma mensagem de erro.  
  
 `nMaxError`  
 O número máximo de caracteres pode conter o buffer, incluindo o **nulo** terminador.  
  
 `pnHelpContext`  
 O endereço de uma **UINT** que receberá a ID do contexto de Ajuda. Se **nulo**, nenhuma ID será retornada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 se nenhum erro de texto da mensagem está disponível.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [CException::GetErrorMessage](../../mfc/reference/cfileexception-class.md#geterrormessage).  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CException](../../mfc/reference/cexception-class.md)   
 [Tratamento de Exceção](../../mfc/exception-handling-in-mfc.md)




