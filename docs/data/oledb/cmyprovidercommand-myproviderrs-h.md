---
title: CCustomCommand (CustomRS.H)
ms.date: 10/22/2018
f1_keywords:
- cmyprovidercommand
- ccustomcommand
helpviewer_keywords:
- OLE DB providers, wizard-generated files
- CMyProviderCommand class in MyProviderRS.H
- CCustomCommand class in CustomRS.H
ms.assetid: b30b956e-cc91-4cf5-9fe6-f8b1ce9cc2a5
ms.openlocfilehash: afa8571173117a23962eb84f6fa5b4cf2c3c46e7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80211751"
---
# <a name="ccustomcommand-customrsh"></a>CCustomCommand (CustomRS.H)

A classe `CCustomCommand` é a implementação do objeto de comando do provedor. Ele fornece a implementação para as interfaces `IAccessor`, `ICommandText`e `ICommandProperties`. A interface `IAccessor` é a mesma do conjunto de linhas. O objeto Command usa o acessador para especificar associações para parâmetros. O objeto Rowset os usa para especificar associações para colunas de saída. A interface `ICommandText` é uma maneira útil de especificar um comando textualmente. Este exemplo usa a interface `ICommandText` mais tarde quando adiciona código personalizado; Ele também substitui o método `ICommand::Execute`. A interface `ICommandProperties` manipula todas as propriedades dos objetos Command e Rowset.

```cpp
// CCustomCommand
class ATL_NO_VTABLE CCustomCommand :
class ATL_NO_VTABLE CCustomCommand :
   public CComObjectRootEx<CComSingleThreadModel>,
   public IAccessorImpl<CCustomCommand>,
   public ICommandTextImpl<CCustomCommand>,
   public ICommandPropertiesImpl<CCustomCommand>,
   public IObjectWithSiteImpl<CCustomCommand>,
   public IConvertTypeImpl<CCustomCommand>,
   public IColumnsInfoImpl<CCustomCommand>
```

A interface `IAccessor` gerencia todas as associações usadas em comandos e conjuntos de linhas. O consumidor chama `IAccessor::CreateAccessor` com uma matriz de estruturas de `DBBINDING`. Cada estrutura de `DBBINDING` contém as informações sobre como as associações de coluna devem ser tratadas (como tipo e comprimento). O provedor recebe as estruturas e, em seguida, determina como os dados devem ser transferidos e se qualquer conversões é necessária. A interface `IAccessor` é usada no objeto Command para lidar com qualquer parâmetro no comando.

O objeto Command também fornece uma implementação de `IColumnsInfo`. OLE DB requer a interface `IColumnsInfo`. A interface permite que o consumidor recupere informações sobre parâmetros do comando. O objeto Rowset usa a interface `IColumnsInfo` para retornar informações sobre as colunas de saída para o provedor.

O provedor também contém uma interface chamada `IObjectWithSite`. A interface `IObjectWithSite` foi implementada no ATL 2,0 e permite que o implementador Transmita informações sobre si mesmo para seu filho. O objeto Command usa as informações de `IObjectWithSite` para informar qualquer objeto de conjunto de linhas gerado sobre quem os criou.

## <a name="see-also"></a>Confira também

[Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)
