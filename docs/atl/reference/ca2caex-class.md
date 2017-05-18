---
title: Classe CA2CAEX | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CA2CAEX
- ATLCONV/ATL::CA2CAEX
- ATLCONV/ATL::CA2CAEX::CA2CAEX
- ATLCONV/ATL::CA2CAEX::m_psz
dev_langs:
- C++
helpviewer_keywords:
- CA2CAEX class
ms.assetid: 388e7c1d-a144-474c-a182-b15f69a74bd8
caps.latest.revision: 20
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
ms.sourcegitcommit: d2d39abf526a58b8442107b5ee816f316ae841f5
ms.openlocfilehash: 9185bc18981898d699aa3f3eeb490c76bf5138fb
ms.contentlocale: pt-br
ms.lasthandoff: 03/31/2017

---
# <a name="ca2caex-class"></a>Classe CA2CAEX
Essa classe é usada por macros de conversão de cadeia de caracteres `CA2CTEX` e `CT2CAEX`e o typedef **CA2CA**.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<int t_nBufferLength = 128>  
class CA2CAEX
```  
  
#### <a name="parameters"></a>Parâmetros  
 `t_nBufferLength`  
 O tamanho do buffer usado no processo de conversão. O comprimento padrão é 128 bytes.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CA2CAEX::CA2CAEX](#ca2caex)|O construtor.|  
|[CA2CAEX:: ~ CA2CAEX](#dtor)|O destruidor.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CA2CAEX::Operator LPCSTR](#operator_lpcstr)|Operador de conversão.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CA2CAEX::m_psz](#m_psz)|O membro de dados que armazena a cadeia de caracteres de origem.|  
  
## <a name="remarks"></a>Comentários  
 A menos que a funcionalidade adicional for necessária, use `CA2CTEX`, `CT2CAEX`, ou **CA2CA** em seu próprio código.  
  
 Esta classe é seguro usar em loops e não de estouro de pilha. Por padrão, as macros e classes de conversão ATL usam a página de código ANSI dos threads atuais para a conversão.  
  
 As seguintes macros baseiam-se esta classe:  
  
- `CA2CTEX`  
  
- `CT2CAEX`  
  
 Typedef seguir baseia-se essa classe:  
  
- **CA2CA**  
  
 Para uma discussão sobre essas macros de conversão de texto, consulte [ATL e MFC Macros de conversão de cadeia de caracteres](string-conversion-macros.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [ATL e MFC Macros de conversão de cadeia de caracteres](string-conversion-macros.md) para obter um exemplo de como usar essas macros de conversão de cadeia de caracteres.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlconv.h  
  
##  <a name="ca2caex"></a>CA2CAEX::CA2CAEX  
 O construtor.  
  
```
CA2CAEX(LPCSTR psz, UINT nCodePage) throw(...);
CA2CAEX(LPCSTR psz) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `psz`  
 A cadeia de caracteres de texto a ser convertido.  
  
 `nCodePage`  
 Não usado nessa classe.  
  
### <a name="remarks"></a>Comentários  
 Cria o buffer necessário para a tradução.  
  
##  <a name="dtor"></a>CA2CAEX:: ~ CA2CAEX  
 O destruidor.  
  
```
~CA2CAEX() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera o buffer alocado.  
  
##  <a name="m_psz"></a>CA2CAEX::m_psz  
 O membro de dados que armazena a cadeia de caracteres de origem.  
  
```
LPCSTR m_psz;
```  
  
##  <a name="operator_lpcstr"></a>CA2CAEX::Operator LPCSTR  
 Operador de conversão.  
  
```  
operator LPCSTR() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a cadeia de caracteres de texto como tipo `LPCSTR`.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CA2AEX](../../atl/reference/ca2aex-class.md)   
 [Classe CA2WEX](../../atl/reference/ca2wex-class.md)   
 [Classe CW2AEX](../../atl/reference/cw2aex-class.md)   
 [Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)   
 [Classe CW2WEX](../../atl/reference/cw2wex-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

