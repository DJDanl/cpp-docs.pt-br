---
title: Classe CA2AEX | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CA2AEX
- ATLCONV/ATL::CA2AEX
- ATLCONV/ATL::CA2AEX::CA2AEX
- ATLCONV/ATL::CA2AEX::m_psz
- ATLCONV/ATL::CA2AEX::m_szBuffer
dev_langs:
- C++
helpviewer_keywords:
- CA2AEX class
ms.assetid: 57dc65df-d9cf-4a84-99d3-6e031dde3664
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
translationtype: Machine Translation
ms.sourcegitcommit: d2d39abf526a58b8442107b5ee816f316ae841f5
ms.openlocfilehash: 979e06cbb4386f61f6490342f16d48739be55e95
ms.lasthandoff: 03/31/2017

---
# <a name="ca2aex-class"></a>Classe CA2AEX
Essa classe é usada pelas macros de conversão de cadeia de caracteres `CA2TEX` e `CT2AEX`e o typedef **CA2A**.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <int t_nBufferLength = 128>
class CA2AEX
```  
  
#### <a name="parameters"></a>Parâmetros  
 `t_nBufferLength`  
 O tamanho do buffer usado no processo de conversão. O comprimento padrão é 128 bytes.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CA2AEX::CA2AEX](#ca2aex)|O construtor.|  
|[CA2AEX:: ~ CA2AEX](#dtor)|O destruidor.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CA2AEX::Operator LPSTR](#operator_lpstr)|Operador de conversão.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CA2AEX::m_psz](#m_psz)|O membro de dados que armazena a cadeia de caracteres de origem.|  
|[CA2AEX::m_szBuffer](#m_szbuffer)|O buffer estático, usado para armazenar a cadeia de caracteres convertida.|  
  
## <a name="remarks"></a>Comentários  
 A menos que a funcionalidade adicional for necessária, use `CA2TEX`, `CT2AEX`, ou **CA2A** em seu próprio código.  
  
 Essa classe contém um buffer de tamanho fixo estático que é usado para armazenar o resultado da conversão. Se o resultado for muito grande para caber no buffer estático, a classe aloca memória usando `malloc`, liberando a memória quando o objeto sair do escopo. Isso garante que, diferentemente do texto macros de conversão disponíveis em versões anteriores do ATL, essa classe é segura usar em loops e que ele não estouro de pilha.  
  
 Se a classe tenta alocar memória no heap e falhar, ele chamará `AtlThrow` com um argumento de **E_OUTOFMEMORY**.  
  
 Por padrão, as classes de conversão de ATL e macros usam página de código ANSI do thread atual para a conversão.  
  
 As seguintes macros baseiam-se esta classe:  
  
- `CA2TEX`  
  
- `CT2AEX`  
  
 Typedef seguir baseia-se essa classe:  
  
- **CA2A**  
  
 Para uma discussão sobre essas macros de conversão de texto, consulte [ATL e MFC Macros de conversão de cadeia de caracteres](string-conversion-macros.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [ATL e MFC Macros de conversão de cadeia de caracteres](string-conversion-macros.md) para obter um exemplo de como usar essas macros de conversão de cadeia de caracteres.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlconv.h  
  
##  <a name="ca2aex"></a>CA2AEX::CA2AEX  
 O construtor.  
  
```
CA2AEX(LPCSTR psz, UINT nCodePage) throw(...);
CA2AEX(LPCSTR psz) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `psz`  
 A cadeia de caracteres de texto a ser convertido.  
  
 `nCodePage`  
 Não usado nessa classe.  
  
### <a name="remarks"></a>Comentários  
 Cria o buffer necessário para a tradução.  
  
##  <a name="dtor"></a>CA2AEX:: ~ CA2AEX  
 O destruidor.  
  
```
~CA2AEX() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera o buffer alocado.  
  
##  <a name="m_psz"></a>CA2AEX::m_psz  
 O membro de dados que armazena a cadeia de caracteres de origem.  
  
```
LPSTR m_psz;
```  
  
##  <a name="m_szbuffer"></a>CA2AEX::m_szBuffer  
 O buffer estático, usado para armazenar a cadeia de caracteres convertida.  
  
```
char m_szBuffer[ t_nBufferLength];
```  
  
##  <a name="operator_lpstr"></a>CA2AEX::Operator LPSTR  
 Operador de conversão.  
  
```
operator LPSTR() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a cadeia de caracteres de texto como tipo **LPSTR**.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CA2CAEX](../../atl/reference/ca2caex-class.md)   
 [Classe CA2WEX](../../atl/reference/ca2wex-class.md)   
 [Classe CW2AEX](../../atl/reference/cw2aex-class.md)   
 [Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)   
 [Classe CW2WEX](../../atl/reference/cw2wex-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
