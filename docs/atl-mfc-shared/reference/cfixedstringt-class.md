---
title: Classe CFixedStringT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CFixedStringT
- CSTRINGT/ATL::CFixedStringT
- CSTRINGT/ATL::CFixedStringT::CFixedStringT
dev_langs:
- C++
helpviewer_keywords:
- CFixedStringT class
- shared classes, CFixedStringT
ms.assetid: 6d4171ba-3104-493a-a6cc-d515f4ba9a4b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 93125d15be32a95d71c763f476fad700dab65a3b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="cfixedstringt-class"></a>Classe CFixedStringT
Essa classe representa um objeto de cadeia de caracteres com um buffer de caracteres fixa.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class StringType, int t_nChars>
class CFixedStringT : private CFixedStringMgr, public StringType
```  
  
#### <a name="parameters"></a>Parâmetros  
 `StringType`  
 Usado como a classe base para o objeto de cadeia de caracteres fixa e pode ser qualquer `CStringT`-com base em tipo. Alguns exemplos incluem `CString`, `CStringA`, e `CStringW`.  
  
 *t_nChars*  
 O número de caracteres armazenados em buffer.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFixedStringT::CFixedStringT](#cfixedstringt)|O construtor para o objeto de cadeia de caracteres.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFixedStringT::operator =](#eq)|Atribui um novo valor para uma `CFixedStringT` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe é um exemplo de uma classe de cadeia de caracteres personalizada com base em `CStringT`. Embora semelhantes, as duas classes diferem na implementação. As principais diferenças entre `CFixedStringT` e `CStringT` são:  
  
-   O buffer do caractere inicial é distribuído como parte do objeto e possui tamanho *t_nChars*. Isso permite que o **CFixedString** objeto ocupar um bloco de memória contígua para fins de desempenho. No entanto, se o conteúdo de um `CFixedStringT` objeto ultrapassar *t_nChars*, o buffer é alocado dinamicamente.  
  
-   O buffer de caracteres para um `CFixedStringT` objeto é sempre o mesmo tamanho ( *t_nChars*). Não há nenhuma limitação no tamanho do buffer de `CStringT` objetos.  
  
-   O Gerenciador de memória para `CFixedStringT` é personalizado para o compartilhamento de um [CStringData](../../atl-mfc-shared/reference/cstringdata-class.md) objeto entre dois ou mais `CFixedStringT` objectsis não permitido. `CStringT` objetos não têm essa limitação.  
  
 Para obter mais informações sobre a personalização de `CFixedStringT` e gerenciamento de memória para objetos de cadeia de caracteres em geral, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IAtlStringMgr`  
  
 `StringType`  
  
 `CFixedStringMgr`  
  
 `CFixedStringT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** cstringt.h  
  
##  <a name="cfixedstringt"></a>  CFixedStringT::CFixedStringT  
 Constrói um objeto `CFixedStringT`.  
  
```
CFixedStringT() throw();
explicit CFixedStringT(IAtlStringMgr* pStringMgr) throw();
CFixedStringT(const CFixedStringT<StringType, t_nChars>& str);
CFixedStringT(const StringType& str);
CFixedStringT(const StringType::XCHAR* psz);
explicit CFixedStringT(const StringType::YCHAR* psz);
explicit CFixedStringT(const unsigned char* psz);
```  
  
### <a name="parameters"></a>Parâmetros  
 `psz`  
 Uma cadeia de caracteres terminada em nulo a serem copiados nisso `CFixedStringT` objeto.  
  
 `str`  
 Um existente `CFixedStringT` objeto sejam copiados para este `CFixedStringT` objeto.  
  
 `pStringMgr`  
 Um ponteiro para o Gerenciador de memória do `CFixedStringT` objeto. Para obter mais informações sobre `IAtlStringMgr` e gerenciamento de memória para `CFixedStringT`, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
### <a name="remarks"></a>Comentários  
 Porque os construtores copiar os dados de entrada para o novo armazenamento alocado, você deve estar ciente que as exceções podem resultar de memória. Observe que alguns desses construtores atuam como funções de conversão.  
  
##  <a name="operator__eq"></a>  CFixedStringT::operator =  
 Reinicializa um existente `CFixedStringT` objeto com novos dados.  
  
```
CFixedStringT<StringType, t_nChars>& operator=(
  const CFixedStringT<StringType, t_nChars>& str);
CFixedStringT<StringType, t_nChars>& operator=(const char* psz);
CFixedStringT<StringType, t_nChars>& operator=(const wchar_t* psz);
CFixedStringT<StringType, t_nChars>& operator=(const unsigned char* psz);
CFixedStringT<StringType, t_nChars>& operator=(const StringType& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma cadeia de caracteres terminada em nulo a serem copiados nisso `CFixedStringT` objeto.  
  
 `psz`  
 Um existente `CFixedStringT` sejam copiados para este `CFixedStringT` objeto.  
  
### <a name="remarks"></a>Comentários  
 Você deve estar ciente de que a memória exceções podem ocorrer sempre que você usar o operador de atribuição, porque o novo armazenamento geralmente é alocado para armazenar resultante `CFixedStringT` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CStringT](../../atl-mfc-shared/reference/cstringt-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes compartilhadas do ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)




