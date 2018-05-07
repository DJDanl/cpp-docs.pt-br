---
title: Classe CLongBinary | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CLongBinary class [MFC]
ms.assetid: f4320059-aeb4-4ee5-bc2b-25f19d898ef5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f7030fdcb59166c0e70a7b2c2471273c913fe459
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="clongbinary-class"></a>Classe CLongBinary
Simplifica o trabalho com objetos de dados binários muito grandes (geralmente chamado de BLOBs ou "objetos binários grandes") em um banco de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CLongBinary : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CLongBinary::CLongBinary](#clongbinary)|Constrói um objeto `CLongBinary`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CLongBinary::m_dwDataLength](#m_dwdatalength)|Contém o tamanho real em bytes do objeto de dados cujo identificador é armazenado em `m_hData`.|  
|[CLongBinary::m_hData](#m_hdata)|Contém um Windows `HGLOBAL` identificador para o objeto de imagem real.|  
  
## <a name="remarks"></a>Comentários  
 Por exemplo, um campo de registro em uma tabela do SQL pode conter um bitmap que representa uma imagem. Um `CLongBinary` objeto armazena esse tipo de objeto e mantém o controle de seu tamanho.  
  
> [!NOTE]
>  Em geral, é melhor prática agora usar [CByteArray](../../mfc/reference/cbytearray-class.md) em conjunto com o [DFX_Binary](record-field-exchange-functions.md#dfx_binary) função. Você ainda pode usar `CLongBinary`, mas em geral `CByteArray` oferece mais funcionalidade sob Win32, porque não há não seja a limitação de tamanho encontrada com 16 bits `CByteArray`. Essa recomendação se aplica a programação com objetos de acesso de dados (DAO), bem como conectividade aberta de banco de dados (ODBC).  
  
 Para usar um `CLongBinary` objeto, declare um membro de dados do campo do tipo `CLongBinary` em sua classe de conjunto de registros. Esse membro será um membro incorporado da classe de conjunto de registros e será construído quando o conjunto de registros é construído. Após o `CLongBinary` objeto for construído, o mecanismo de troca (RFX) campos de registro carrega o objeto de dados de um campo no registro atual na fonte de dados e armazena-o novamente para o registro quando o registro é atualizado. RFX as consultas a fonte de dados para o tamanho do objeto binário grande, aloca armazenamento para ela (por meio de `CLongBinary` do objeto `m_hData` membro de dados) e armazena um `HGLOBAL` identificador para os dados em `m_hData`. RFX também armazena o tamanho real do objeto de dados no `m_dwDataLength` membro de dados. Trabalhar com os dados no objeto por meio de `m_hData`, usando as mesmas técnicas que normalmente usaria para manipular os dados armazenados em um Windows `HGLOBAL` tratar.  
  
 Quando você destruir o conjunto de registros, o item inserido `CLongBinary` objeto também é destruído e seu destruidor desaloca o `HGLOBAL` identificador de dados.  
  
 Para obter mais informações sobre objetos grandes e o uso de `CLongBinary`, consulte os artigos [conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md) e [conjunto de registros: Trabalhando com itens de dados grandes (ODBC)](../../data/odbc/recordset-working-with-large-data-items-odbc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CLongBinary`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb_.h  
  
##  <a name="clongbinary"></a>  CLongBinary::CLongBinary  
 Constrói um objeto `CLongBinary`.  
  
```  
CLongBinary();
```  
  
##  <a name="m_dwdatalength"></a>  CLongBinary::m_dwDataLength  
 Armazena o tamanho real em bytes dos dados armazenados no `HGLOBAL` tratar no `m_hData`.  
  
```  
SQLULEN m_dwDataLength;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse tamanho pode ser menor que o tamanho do bloco de memória alocado para os dados. Chame o Win32 [GLobalSize](http://msdn.microsoft.com/library/windows/desktop/aa366593) função para obter o tamanho alocado.  
  
##  <a name="m_hdata"></a>  CLongBinary::m_hData  
 Armazena um Windows `HGLOBAL` lidar com os dados reais de objeto binário grande.  
  
```  
HGLOBAL m_hData;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CRecordset](../../mfc/reference/crecordset-class.md)
