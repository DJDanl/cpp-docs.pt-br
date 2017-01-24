---
title: "Caminhos de pesquisa em regras | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "regras de inferência em NMAKE"
  - "regras, inferência"
  - "pesquisar caminhos em regras de inferência NMAKE"
ms.assetid: 38feded6-536d-425d-bf40-fff3173a5506
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Caminhos de pesquisa em regras
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

```  
{frompath}.fromext{topath}.toext:  
   commands  
```  
  
## Comentários  
 Uma regra de inferência se aplica a uma dependência somente se os caminhos especificados na dependência corresponderem exatamente aos caminhos de inferência\- regra.  Especifique o diretório de dependente do *frompath* e o diretório de destino no *topath*; nenhum espaço é permitido.  Especificar apenas um caminho para cada extensão.  Um caminho em uma extensão requer um caminho em outro.  Para especificar o diretório atual, use um ponto \(.\) ou vazio chaves \({}\).  Macros podem representar *o frompath* e *o topath*; são chamados durante pré\-processamento.  
  
## Exemplo  
  
### Código  
  
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
  
## Consulte também  
 [Definindo uma regra](../build/defining-a-rule.md)