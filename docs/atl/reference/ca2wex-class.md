---
title: Classe CA2WEX | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 7c1029d0d9cb1abb1980f97c9541e2c1ce40b539
ms.lasthandoff: 02/25/2017

---
# <a name="ca2wex-class"></a>Classe CA2WEX
Essa classe é usada, as macros de conversão de cadeia de caracteres `CA2TEX`, `CA2CTEX`, `CT2WEX`, e `CT2CWEX`e o typedef **CA2W**.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <int t_nBufferLength = 128>
class CA2WEX
```  
  
#### <a name="parameters"></a>Parâmetros  
 `t_nBufferLength`  
 O tamanho do buffer usado no processo de conversão. O comprimento padrão é 128 bytes.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
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
 A menos que a funcionalidade adicional for necessária, use `CA2TEX`, `CA2CTEX`, `CT2WEX`, `CT2CWEX`, ou **CA2W** em seu código.  
  
 Essa classe contém um buffer de tamanho fixo estático que é usado para armazenar o resultado da conversão. Se o resultado for muito grande para caber no buffer estático, a classe aloca memória usando `malloc`, liberando a memória quando o objeto sair do escopo. Isso garante que, diferentemente do texto macros de conversão disponíveis em versões anteriores do ATL, essa classe é seguro usar em loops e que ele não estouram a pilha.  
  
 Se a classe tenta alocar memória no heap e falhar, ele chamará `AtlThrow` com um argumento de **E_OUTOFMEMORY**.  
  
 Por padrão, as macros e classes de conversão ATL usam página de código ANSI do thread atual para a conversão. Se você quiser substituir esse comportamento para uma conversão específica, especifique a página de código como o segundo parâmetro para o construtor da classe.  
  
 As macros a seguir baseiam-se em sua classe:  
  
- `CA2TEX`  
  
- `CA2CTEX`  
  
- `CT2WEX`  
  
- `CT2CWEX`  
  
 Typedef a seguir baseia-se em sua classe:  
  
- **CA2W**  
  
 Para uma discussão sobre essas macros de conversão de texto, consulte [Macros de conversão de cadeia de caracteres MFC e ATL](http://msdn.microsoft.com/library/8f53659e-0464-4424-97db-6b8453c49863).  
  
## <a name="example"></a>Exemplo  
 Consulte [Macros de conversão de cadeia de caracteres MFC e ATL](http://msdn.microsoft.com/library/8f53659e-0464-4424-97db-6b8453c49863) para obter um exemplo de como usar essas macros de conversão de cadeia de caracteres.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Atlconv. h  
  
##  <a name="ca2wex"></a>CA2WEX::CA2WEX  
 O construtor.  
  
```
CA2WEX(LPCSTR psz, UINT nCodePage) throw(...);
CA2WEX(LPCSTR psz) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `psz`  
 A cadeia de caracteres de texto a ser convertido.  
  
 `nCodePage`  
 A página de código usada para executar a conversão. Consulte a discussão de parâmetro de página de código para o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] função [MultiByteToWideChar](http://msdn.microsoft.com/library/windows/desktop/dd319072) para obter mais detalhes.  
  
### <a name="remarks"></a>Comentários  
 Aloca o buffer usado no processo de conversão.  
  
##  <a name="dtor"></a>CA2WEX:: ~ CA2WEX  
 O destruidor.  
  
```
~CA2WEX() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera o buffer alocado.  
  
##  <a name="m_psz"></a>CA2WEX::m_psz  
 O membro de dados que armazena a cadeia de caracteres de origem.  
  
```
LPWSTR m_psz;
```  
  
##  <a name="m_szbuffer"></a>CA2WEX::m_szBuffer  
 O buffer estático, usado para armazenar a cadeia de caracteres convertida.  
  
```
wchar_t m_szBuffer[t_nBufferLength];
```  
  
##  <a name="operator_lpwstr"></a>CA2WEX::Operator LPWSTR  
 Operador de conversão.  
  
```  
operator LPWSTR() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a cadeia de caracteres de texto como tipo **LPWSTR.**  
  
## <a name="see-also"></a>Consulte também  
 [Classe CA2AEX](../../atl/reference/ca2aex-class.md)   
 [Classe CA2CAEX](../../atl/reference/ca2caex-class.md)   
 [Classe CW2AEX](../../atl/reference/cw2aex-class.md)   
 [Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)   
 [Classe CW2WEX](../../atl/reference/cw2wex-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

