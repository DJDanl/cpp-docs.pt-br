---
title: Classe CA2WEX | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CA2WEX
- ATLCONV/ATL::CA2WEX
- ATLCONV/ATL::CA2WEX::CA2WEX
- ATLCONV/ATL::CA2WEX::m_psz
- ATLCONV/ATL::CA2WEX::m_szBuffer
dev_langs:
- C++
helpviewer_keywords:
- CA2WEX class
ms.assetid: 317d9ffb-e84f-47e8-beda-57e28fb19124
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 095d0d74fe5ff6eb30866b619e201a029b754d38
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43202170"
---
# <a name="ca2wex-class"></a>Classe CA2WEX
Essa classe é usada, as macros de conversão de cadeia de caracteres CA2TEX, CA2CTEX, CT2WEX e CT2CWEX e typedef CA2W.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <int t_nBufferLength = 128>
class CA2WEX
```  
  
#### <a name="parameters"></a>Parâmetros  
 *t_nBufferLength*  
 O tamanho do buffer usado no processo de tradução. O comprimento padrão é 128 bytes.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CA2WEX::CA2WEX](#ca2wex)|O construtor.|  
|[CA2WEX:: ~ CA2WEX](#dtor)|O destruidor.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CA2WEX::Operator LPWSTR](#operator_lpwstr)|Operador de conversão.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CA2WEX::m_psz](#m_psz)|O membro de dados que armazena a cadeia de caracteres de origem.|  
|[CA2WEX::m_szBuffer](#m_szbuffer)|O buffer estático, usado para armazenar a cadeia de caracteres convertida.|  
  
## <a name="remarks"></a>Comentários  
 A menos que a funcionalidade adicional for necessária, use CA2TEX, CA2CTEX, CT2WEX, CT2CWEX ou CA2W em seu código.  
  
 Essa classe contém um buffer estático de tamanho fixo que é usado para armazenar o resultado da conversão. Se o resultado for muito grande para caber no buffer estático, a classe aloca memória usando **malloc**, liberando a memória quando o objeto sai do escopo. Isso garante que, diferentemente do texto macros de conversão disponíveis em versões anteriores da ATL, essa classe é seguro para ser usado em loops e que ele não estouram a pilha.  
  
 Se a classe tenta alocar memória no heap e falhar, ele chamará `AtlThrow` com um argumento de E_OUTOFMEMORY.  
  
 Por padrão, as macros e classes de conversão ATL usam página de código ANSI do thread atual para a conversão. Se você quiser substituir esse comportamento para uma conversão específica, especifique a página de código como o segundo parâmetro para o construtor da classe.  
  
 As macros a seguir se baseiam nessa classe:  
  
- CA2TEX  
  
- CA2CTEX  
  
- CT2WEX  
  
- CT2CWEX  
  
 O typedef seguir baseia-se nessa classe:  
  
- CA2W  
  
 Para uma discussão sobre essas macros de conversão de texto, consulte [ATL e Macros de conversão de cadeia de caracteres MFC](string-conversion-macros.md).  
  
## <a name="example"></a>Exemplo  
 Ver [ATL e Macros de conversão de cadeia de caracteres MFC](string-conversion-macros.md) para obter um exemplo de como usar essas macros de conversão de cadeia de caracteres.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Atlconv. h  
  
##  <a name="ca2wex"></a>  CA2WEX::CA2WEX  
 O construtor.  
  
```
CA2WEX(LPCSTR psz, UINT nCodePage) throw(...);
CA2WEX(LPCSTR psz) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *psz*  
 A cadeia de caracteres de texto a ser convertido.  
  
 *nCodePage*  
 A página de código usada para realizar a conversão. Consulte a discussão de parâmetro de página de código para a função do SDK do Windows [MultiByteToWideChar](/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) para obter mais detalhes.  
  
### <a name="remarks"></a>Comentários  
 Aloca um buffer usado no processo de tradução.  
  
##  <a name="dtor"></a>  CA2WEX:: ~ CA2WEX  
 O destruidor.  
  
```
~CA2WEX() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera o buffer alocado.  
  
##  <a name="m_psz"></a>  CA2WEX::m_psz  
 O membro de dados que armazena a cadeia de caracteres de origem.  
  
```
LPWSTR m_psz;
```  
  
##  <a name="m_szbuffer"></a>  CA2WEX::m_szBuffer  
 O buffer estático, usado para armazenar a cadeia de caracteres convertida.  
  
```
wchar_t m_szBuffer[t_nBufferLength];
```  
  
##  <a name="operator_lpwstr"></a>  CA2WEX::Operator LPWSTR  
 Operador de conversão.  
  
```  
operator LPWSTR() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a cadeia de caracteres de texto enquanto digita LPWSTR.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CA2AEX](../../atl/reference/ca2aex-class.md)   
 [Classe CA2CAEX](../../atl/reference/ca2caex-class.md)   
 [Classe CW2AEX](../../atl/reference/cw2aex-class.md)   
 [Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)   
 [Classe CW2WEX](../../atl/reference/cw2wex-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
