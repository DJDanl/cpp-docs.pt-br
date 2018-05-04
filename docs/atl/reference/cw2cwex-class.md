---
title: Classe CW2CWEX | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CW2CWEX
- ATLCONV/ATL::CW2CWEX
- ATLCONV/ATL::CW2CWEX::CW2CWEX
- ATLCONV/ATL::CW2CWEX::m_psz
dev_langs:
- C++
helpviewer_keywords:
- CW2CWEX class
ms.assetid: d654b22b-05a6-410f-a0ec-9a2cbbb4cca7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 671311b0788438d7b92dad9d9137e28cbb88df60
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="cw2cwex-class"></a>Classe CW2CWEX
Essa classe é usada pelas macros de conversão de cadeia de caracteres `CW2CTEX` e `CT2CWEX`e o typedef `CW2W`.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<int t_nBufferLength = 128>  
class CW2CWEX
```  
  
#### <a name="parameters"></a>Parâmetros  
 `t_nBufferLength`  
 O tamanho do buffer usado no processo de conversão. O comprimento padrão é 128 bytes.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CW2CWEX::CW2CWEX](#cw2cwex)|O construtor.|  
|[CW2CWEX:: ~ CW2CWEX](#dtor)|O destruidor.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CW2CWEX::Operator LPCWSTR](#operator_lpcwstr)|Operador de conversão.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CW2CWEX::m_psz](#m_psz)|O membro de dados que armazena a cadeia de caracteres de origem.|  
  
## <a name="remarks"></a>Comentários  
 A menos que a funcionalidade adicional for necessária, use `CW2CTEX`, `CT2CWEX`, ou `CW2W` em seu código.  
  
 Esta classe é seguro usar em loops e não de estouro de pilha. Por padrão, as classes de conversão de ATL e macros usam página de código ANSI do thread atual para a conversão.  
  
 As seguintes macros baseiam-se esta classe:  
  
- `CW2CTEX`  
  
- `CT2CWEX`  
  
 Typedef seguir baseia-se essa classe:  
  
- `CW2W`  
  
 Para uma discussão sobre essas macros de conversão de texto, consulte [ATL e MFC Macros de conversão de cadeia de caracteres](string-conversion-macros.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [ATL e MFC Macros de conversão de cadeia de caracteres](string-conversion-macros.md) para obter um exemplo de como usar essas macros de conversão de cadeia de caracteres.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlconv.h  
  
##  <a name="cw2cwex"></a>  CW2CWEX::CW2CWEX  
 O construtor.  
  
```
CW2CWEX(LPCWSTR psz, UINT nCodePage) throw(...);  
CW2CWEX(LPCWSTR psz) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `psz`  
 A cadeia de caracteres de texto a ser convertido.  
  
 `nCodePage`  
 A página de código. Não usado nessa classe.  
  
### <a name="remarks"></a>Comentários  
 Aloca o buffer usado no processo de conversão.  
  
##  <a name="dtor"></a>  CW2CWEX:: ~ CW2CWEX  
 O destruidor.  
  
```
~CW2CWEX() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera o buffer alocado.  
  
##  <a name="m_psz"></a>  CW2CWEX::m_psz  
 O membro de dados que armazena a cadeia de caracteres de origem.  
  
```
LPCWSTR m_psz;
```  
  
##  <a name="operator_lpcwstr"></a>  CW2CWEX::Operator LPCWSTR  
 Operador de conversão.  
  
```  
operator LPCWSTR() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a cadeia de caracteres de texto como tipo **LPCWSTR.**  
  
## <a name="see-also"></a>Consulte também  
 [Classe CA2AEX](../../atl/reference/ca2aex-class.md)   
 [Classe CA2CAEX](../../atl/reference/ca2caex-class.md)   
 [Classe CA2WEX](../../atl/reference/ca2wex-class.md)   
 [Classe CW2AEX](../../atl/reference/cw2aex-class.md)   
 [Classe CW2WEX](../../atl/reference/cw2wex-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
