---
title: demarcadores de pesquisa em regras
ms.date: 11/04/2016
helpviewer_keywords:
- search paths in NMAKE inference rules
- inference rules in NMAKE
- rules, inference
ms.assetid: 38feded6-536d-425d-bf40-fff3173a5506
ms.openlocfilehash: 26b02fa76920f0d0ff380dacd5aa76cfe8e92c79
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50649963"
---
# <a name="search-paths-in-rules"></a>demarcadores de pesquisa em regras

```
{frompath}.fromext{topath}.toext:
   commands
```

## <a name="remarks"></a>Comentários

Uma regra de inferência se aplica a uma dependência somente se os caminhos especificados na dependência exatamente correspondem os caminhos de regra de inferência de tipos. Especifique o diretório do dependente no *frompath* e o diretório de destino no *topath*; não são permitidos espaços. Especifique apenas um caminho para cada extensão. Um caminho em uma extensão requer um caminho no outro. Para especificar o diretório atual, use um ponto (.) ou chaves vazias ({}). Macros podem representar *frompath* e *topath*; eles são chamados durante o pré-processamento.

## <a name="example"></a>Exemplo

### <a name="code"></a>Código

```
{dbi\}.cpp{$(ODIR)}.obj::
        $(CC) $(CFLAGS) $(YUDBI) $<

{ilstore\}.cpp{$(ODIR)}.obj::
        $(CC) $(CFLAGS) $<

{misc\}.cpp{$(ODIR)}.obj::
        $(CC) $(CFLAGS) $(YUPDB) $<

{misc\}.c{$(ODIR)}.obj::
        $(CC) $(CFLAGS) $<

{msf\}.cpp{$(ODIR)}.obj::
        $(CC) $(CFLAGS) $<

{bsc\}.cpp{$(ODIR)}.obj::
        $(CC) $(CFLAGS) $(YUPDB) $<

{mre\}.cpp{$(ODIR)}.obj::
        $(CC) $(CFLAGS) $(YUPDB) $<

{namesrvr\}.cpp{$(ODIR)}.obj::
        $(CC) $(CFLAGS) $(YUPDB) $<

{src\cvr\}.cpp{$(ODIR)}.obj::
        $(CC) $(CFLAGS) $<
```

## <a name="see-also"></a>Consulte também

[Definindo uma regra](../build/defining-a-rule.md)