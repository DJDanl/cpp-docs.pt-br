---
title: Classe CFieldExchange | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- CFieldExchange
- AFXDB/CFieldExchange
- AFXDB/CFieldExchange::IsFieldType
- AFXDB/CFieldExchange::SetFieldType
dev_langs:
- C++
helpviewer_keywords:
- CFieldExchange [MFC], IsFieldType
- CFieldExchange [MFC], SetFieldType
ms.assetid: 24c5c0b3-06a6-430e-9b6f-005a2c65e29f
caps.latest.revision: 24
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d20a89e48475a0226d76ac719459b1b99cc4e355
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cfieldexchange-class"></a>Classe CFieldExchange
Dá suporte a troca de campos de registro (RFX) e as rotinas de troca (RFX em massa) de campos de registro em massa usadas pelas classes de banco de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CFieldExchange  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFieldExchange::IsFieldType](#isfieldtype)|Retorna zero se a operação atual for apropriado para o tipo de campo que está sendo atualizado.|  
|[CFieldExchange::SetFieldType](#setfieldtype)|Especifica o tipo de membro de dados do conjunto de registros, coluna ou parâmetro — representado por todas as chamadas seguintes de funções RFX até a próxima chamada para `SetFieldType`.|  
  
## <a name="remarks"></a>Comentários  
 `CFieldExchange`não tem uma classe base.  
  
 Use essa classe se você estiver escrevendo rotinas de troca de dados para tipos de dados personalizados ou quando você estiver implementando a busca de linhas em massa; Caso contrário, você não use diretamente desta classe. RFX e RFX em massa troca dados entre os membros de dados do campo de seu objeto de conjunto de registros e campos correspondentes do registro atual na fonte de dados.  
  
> [!NOTE]
>  Se você estiver trabalhando com as classes de objetos de acesso de dados (DAO) em vez de classes de conectividade de banco de dados aberto (ODBC), use a classe [CDaoFieldExchange](../../mfc/reference/cdaofieldexchange-class.md) em vez disso. Para obter mais informações, consulte o artigo [banco de dados: Visão geral de programação](../../data/data-access-programming-mfc-atl.md).  
  
 Um `CFieldExchange` objeto fornece as informações de contexto necessário para a troca de campos de registro ou a troca de campos de registro em massa se colocar. `CFieldExchange`objetos dão suporte a um número de operações, incluindo parâmetros de associação e os membros de dados de campo e definir vários sinalizadores nos campos do registro atual. RFX e RFX em massa operações são executadas em membros de dados de classe de conjunto de registros de tipos definidos pelo `enum` **FieldType** em `CFieldExchange`. Possíveis **FieldType** os valores são:  
  
- **CFieldExchange::outputColumn** para membros de dados do campo.  
  
- **CFieldExchange::inputParam** ou **CFieldExchange::param** para membros de dados do parâmetro de entrada.  
  
- **CFieldExchange::outputParam** para membros de dados de parâmetro de saída.  
  
- **CFieldExchange::inoutParam** para membros de dados do parâmetro de entrada/saída.  
  
 A maioria dos membros de funções e os dados de membro da classe é fornecida para escrever suas próprias rotinas RFX personalizadas. Você usará `SetFieldType` com frequência. Para obter mais informações, consulte os artigos [troca de campos de registro (RFX)](../../data/odbc/record-field-exchange-rfx.md) e [conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md). Para obter informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md). Para obter detalhes sobre as funções globais RFX e RFX em massa, consulte [funções de troca de campos do registro](../../mfc/reference/record-field-exchange-functions.md) na seção de Macros e globais MFC essa referência.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CFieldExchange`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb.h  
  
##  <a name="isfieldtype"></a>CFieldExchange::IsFieldType  
 Se você gravar sua própria função RFX, chame `IsFieldType` no início de sua função para determinar se a operação atual pode ser executada em um tipo de membro de dados campo ou parâmetro específico (um **CFieldExchange::outputColumn**, **CFieldExchange::inputParam**, **CFieldExchange::param**, **CFieldExchange::outputParam**, ou **CFieldExchange::inoutParam** ).  
  
```  
BOOL IsFieldType(UINT* pnField);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pnField*  
 O número sequencial do membro de dados de campo ou parâmetro será retornado nesse parâmetro. Esse número corresponde à ordem do membro de dados no [CRecordset::DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) ou [CRecordset::DoBulkFieldExchange](../../mfc/reference/crecordset-class.md#dobulkfieldexchange) função.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação atual pode ser executada no tipo de parâmetro ou campo atual.  
  
### <a name="remarks"></a>Comentários  
 Segue o modelo das funções RFX existentes.  
  
##  <a name="setfieldtype"></a>CFieldExchange::SetFieldType  
 Você precisa de uma chamada para `SetFieldType` em sua classe de conjunto de registros [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) ou [DoBulkFieldExchange](../../mfc/reference/crecordset-class.md#dobulkfieldexchange) substituir.  
  
```  
void SetFieldType(UINT nFieldType);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nFieldType`  
 Um valor de **enum FieldType**, declarado em `CFieldExchange`, que pode ser um dos seguintes:  
  
- **CFieldExchange::outputColumn**  
  
- **CFieldExchange::inputParam**  
  
- **CFieldExchange::param**  
  
- **CFieldExchange::outputParam**  
  
- **CFieldExchange::inoutParam**  
  
### <a name="remarks"></a>Comentários  
 Para membros de dados do campo, você deve chamar `SetFieldType` com um parâmetro de **CFieldExchange::outputColumn**, seguido por chamadas para as funções RFX ou RFX em massa. Se você não implementou a busca de linhas em massa, ClassWizard coloca essa `SetFieldType` chamar para você na seção de mapa de campo de `DoFieldExchange`.  
  
 Se você parametrizar sua classe de conjunto de registros, você deve chamar `SetFieldType` novamente, fora de qualquer seção de mapa de campo, seguido por RFX chamadas para todos os membros de dados de parâmetro. Cada tipo de membro de dados do parâmetro deve ter seu próprio `SetFieldType` chamar. A tabela a seguir distingue os diferentes valores que você pode passar para `SetFieldType` para representar os membros de dados do parâmetro de sua classe:  
  
|Valor do parâmetro SetFieldType|Tipo de membro de dados do parâmetro|  
|----------------------------------|-----------------------------------|  
|**CFieldExchange::inputParam**|Parâmetro de entrada. Um valor que é passado para do conjunto de registros consulta ou procedimento armazenado.|  
|**CFieldExchange::param**|Mesmo que **CFieldExchange::inputParam**.|  
|**CFieldExchange::outputParam**|Parâmetro de saída. Um valor de retorno do procedimento armazenado do conjunto de registros.|  
|**CFieldExchange::inoutParam**|Parâmetro de entrada/saída. Um valor que é passado para e retornado pelo procedimento armazenado do conjunto de registros.|  
  
 Em geral, cada grupo de chamadas de função RFX associados a membros de dados do campo ou membros de dados do parâmetro deve ser precedido por uma chamada para `SetFieldType`. O `nFieldType` parâmetro de cada `SetFieldType` chamada identifica o tipo dos membros de dados representado pelas chamadas de função RFX que seguem o `SetFieldType` chamar.  
  
 Para obter mais informações sobre como lidar com os parâmetros de entrada/saída e saída, consulte o `CRecordset` função de membro [FlushResultSet](../../mfc/reference/crecordset-class.md#flushresultset). Para obter mais informações sobre as funções RFX e RFX em massa, consulte o tópico [funções de troca de campos do registro](../../mfc/reference/record-field-exchange-functions.md). Para obter informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
### <a name="example"></a>Exemplo  
 Este exemplo mostra várias chamadas para funções RFX acompanhada de chamadas para `SetFieldType`. Observe que `SetFieldType` é chamado por meio de `pFX` ponteiro para um `CFieldExchange` objeto.  
  
 [!code-cpp[NVC_MFCDatabase#33](../../mfc/codesnippet/cpp/cfieldexchange-class_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CRecordset](../../mfc/reference/crecordset-class.md)
