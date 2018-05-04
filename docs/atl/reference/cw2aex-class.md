---
title: Classe CW2AEX | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CW2AEX
- ATLCONV/ATL::CW2AEX
- ATLCONV/ATL::CW2AEX::CW2AEX
- ATLCONV/ATL::CW2AEX::m_psz
- ATLCONV/ATL::CW2AEX::m_szBuffer
dev_langs:
- C++
helpviewer_keywords:
- CW2AEX class
ms.assetid: 44dc2cf5-dd30-440b-a9b9-b21b43f49843
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 62fd48a34b82e0671d417a882e040a87a7691c01
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="cw2aex-class"></a>Classe CW2AEX
Essa classe é usada pelas macros de conversão de cadeia de caracteres `CT2AEX`, `CW2TEX`, `CW2CTEX`, e `CT2CAEX`e o typedef **CW2A**.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<int t_nBufferLength = 128>  
class CW2AEX
```  
  
#### <a name="parameters"></a>Parâmetros  
 `t_nBufferLength`  
 O tamanho do buffer usado no processo de conversão. O comprimento padrão é 128 bytes.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CW2AEX::CW2AEX](#cw2aex)|O construtor.|  
|[CW2AEX:: ~ CW2AEX](#dtor)|O destruidor.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CW2AEX::Operator LPSTR](#operator_lpstr)|Operador de conversão.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CW2AEX::m_psz](#m_psz)|O membro de dados que armazena a cadeia de caracteres de origem.|  
|[CW2AEX::m_szBuffer](#m_szbuffer)|O buffer estático, usado para armazenar a cadeia de caracteres convertida.|  
  
## <a name="remarks"></a>Comentários  
 A menos que a funcionalidade adicional for necessária, use `CT2AEX`, `CW2TEX`, `CW2CTEX`, `CT2CAEX`, ou **CW2A** em seu código.  
  
 Essa classe contém um buffer de tamanho fixo estático que é usado para armazenar o resultado da conversão. Se o resultado for muito grande para caber no buffer estático, a classe aloca memória usando `malloc`, liberando a memória quando o objeto sair do escopo. Isso garante que, diferentemente do texto macros de conversão disponíveis em versões anteriores do ATL, essa classe é segura usar em loops e que ele não estouro de pilha.  
  
 Se a classe tenta alocar memória no heap e falhar, ele chamará `AtlThrow` com um argumento de **E_OUTOFMEMORY**.  
  
 Por padrão, as classes de conversão de ATL e macros usam página de código ANSI do thread atual para a conversão. Se você quiser substituir esse comportamento para uma conversão específica, especifique a página de código como o segundo parâmetro para o construtor da classe.  
  
 As seguintes macros baseiam-se esta classe:  
  
- `CT2AEX`  
  
- `CW2TEX`  
  
- `CW2CTEX`  
  
- `CT2CAEX`  
  
 Typedef seguir baseia-se essa classe:  
  
- **CW2A**  
  
 Para uma discussão sobre essas macros de conversão de texto, consulte [ATL e MFC Macros de conversão de cadeia de caracteres](string-conversion-macros.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [ATL e MFC Macros de conversão de cadeia de caracteres](string-conversion-macros.md) para obter um exemplo de como usar essas macros de conversão de cadeia de caracteres.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlconv.h  
  
##  <a name="cw2aex"></a>  CW2AEX::CW2AEX  
 O construtor.  
  
```
CW2AEX(LPCWSTR psz, UINT nCodePage) throw(...);  
CW2AEX(LPCWSTR psz) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `psz`  
 A cadeia de caracteres de texto a ser convertido.  
  
 `nCodePage`  
 A página de código usada para executar a conversão. Consulte a discussão de parâmetro de página de código para a função do SDK do Windows [MultiByteToWideChar](http://msdn.microsoft.com/library/windows/desktop/dd319072) para obter mais detalhes.  
  
### <a name="remarks"></a>Comentários  
 Aloca o buffer usado no processo de conversão.  
  
##  <a name="dtor"></a>  CW2AEX:: ~ CW2AEX  
 O destruidor.  
  
```
~CW2AEX() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera o buffer alocado.  
  
##  <a name="m_psz"></a>  CW2AEX::m_psz  
 O membro de dados que armazena a cadeia de caracteres de origem.  
  
```
LPSTR m_psz;
```  
  
##  <a name="m_szbuffer"></a>  CW2AEX::m_szBuffer  
 O buffer estático, usado para armazenar a cadeia de caracteres convertida.  
  
```
char m_szBuffer[t_nBufferLength];
```  
  
##  <a name="operator_lpstr"></a>  CW2AEX::Operator LPSTR  
 Operador de conversão.  
  
```  
operator LPSTR() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a cadeia de caracteres de texto como tipo **LPSTR.**  
  
## <a name="see-also"></a>Consulte também  
 [Classe CA2AEX](../../atl/reference/ca2aex-class.md)   
 [Classe CA2CAEX](../../atl/reference/ca2caex-class.md)   
 [Classe CA2WEX](../../atl/reference/ca2wex-class.md)   
 [Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)   
 [Classe CW2WEX](../../atl/reference/cw2wex-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
