---
title: Classe CLongBinary | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CLongBinary
- AFXDB_/CLongBinary
- AFXDB_/CLongBinary::CLongBinary
- AFXDB_/CLongBinary::m_dwDataLength
- AFXDB_/CLongBinary::m_hData
dev_langs:
- C++
helpviewer_keywords:
- BLOB (binary large object)
- CLongBinary class
- BLOB (binary large object), CLongBinary class
ms.assetid: f4320059-aeb4-4ee5-bc2b-25f19d898ef5
caps.latest.revision: 21
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: bb73604ee4d15f3a71be8514f348ad265064928a
ms.lasthandoff: 02/25/2017

---
# <a name="clongbinary-class"></a>Classe CLongBinary
Simplifica o trabalho com objetos de dados binários muito grandes (geralmente chamado de BLOBs ou "objetos binários grandes") em um banco de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CLongBinary : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CLongBinary::CLongBinary](#clongbinary)|Constrói um objeto `CLongBinary`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CLongBinary::m_dwDataLength](#m_dwdatalength)|Contém o real tamanho em bytes do objeto de dados cujo identificador é armazenado em `m_hData`.|  
|[CLongBinary::m_hData](#m_hdata)|Contém um Windows `HGLOBAL` identificador para o objeto de imagem real.|  
  
## <a name="remarks"></a>Comentários  
 Por exemplo, um campo de registro em uma tabela do SQL pode conter um bitmap que representa uma imagem. Um `CLongBinary` objeto armazena tal objeto e mantém o controle de seu tamanho.  
  
> [!NOTE]
>  Em geral, é prática recomendada agora usar [CByteArray](../../mfc/reference/cbytearray-class.md) em conjunto com o [DFX_Binary](http://msdn.microsoft.com/library/678021a3-2e46-44d7-8528-71bb692dcc07) função. Você ainda pode usar `CLongBinary`, mas em geral `CByteArray` fornece mais funcionalidade em Win32, porque não há não seja a limitação de tamanho encontrada com 16 bits `CByteArray`. Essa recomendação se aplica a programação com objetos de acesso de dados (DAO), bem como conectividade aberta de banco de dados (ODBC).  
  
 Para usar um `CLongBinary` objeto, declarar um membro de dados do campo de tipo `CLongBinary` em sua classe de conjunto de registros. Esse membro será um membro da classe de conjunto de registros inseridos e será criado quando o conjunto de registros é construído. Após o `CLongBinary` objeto é construído, o mecanismo de troca (RFX) campos de registro carrega o objeto de dados de um campo no registro atual na fonte de dados e armazená-lo novamente o registro quando o registro é atualizado. RFX consulta de fonte de dados para o tamanho do objeto binário grande, aloca armazenamento para ele (por meio de `CLongBinary` do objeto `m_hData` membro de dados) e armazena um `HGLOBAL` identificador para os dados no `m_hData`. RFX também armazena o tamanho real do objeto de dados a `m_dwDataLength` membro de dados. Trabalhar com os dados no objeto por meio de `m_hData`, usando as mesmas técnicas que você normalmente usaria para manipular os dados armazenados em um Windows `HGLOBAL` tratar.  
  
 Quando você destruir o conjunto de registros, o item inserido `CLongBinary` objeto também é destruído e seu destruidor desaloca os `HGLOBAL` identificador de dados.  
  
 Para obter mais informações sobre objetos grandes e o uso de `CLongBinary`, consulte os artigos [conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md) e [conjunto de registros: Trabalhando com itens de dados grandes (ODBC)](../../data/odbc/recordset-working-with-large-data-items-odbc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CLongBinary`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb_.h  
  
##  <a name="clongbinary"></a>CLongBinary::CLongBinary  
 Constrói um objeto `CLongBinary`.  
  
```  
CLongBinary();
```  
  
##  <a name="m_dwdatalength"></a>CLongBinary::m_dwDataLength  
 Armazena o real tamanho em bytes dos dados armazenados na `HGLOBAL` manipular em `m_hData`.  
  
```  
SQLULEN m_dwDataLength;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse tamanho pode ser menor que o tamanho do bloco de memória alocado para os dados. Chamar o Win32 [GLobalSize](http://msdn.microsoft.com/library/windows/desktop/aa366593) função para obter o tamanho alocado.  
  
##  <a name="m_hdata"></a>CLongBinary::m_hData  
 Armazena um Windows `HGLOBAL` identificador para os dados reais de objeto binário grande.  
  
```  
HGLOBAL m_hData;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CRecordset](../../mfc/reference/crecordset-class.md)

