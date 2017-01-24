---
title: "/ORDER (colocar fun&#231;&#245;es na ordem) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCLinkerTool.FunctionOrder"
  - "/order"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /ORDER"
  - "ferramenta LINK [C++], otimização de programa"
  - "ferramenta LINK [C++], ajuste swap"
  - "opção de vinculador ORDER"
  - "opção de vinculador -ORDER"
  - "paginação, otimizando"
ms.assetid: ecf5eb3e-e404-4e86-9a91-4e5ec157261a
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /ORDER (colocar fun&#231;&#245;es na ordem)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/ORDER:@filename  
```  
  
## Parâmetros  
 *filename*  
 Um arquivo de texto que especifica a ordem de vinculação para COMDAT funções.  
  
## Comentários  
 A opção \/ORDER diz o LINK para otimizar seu programa colocando determinado COMDATs na imagem em uma ordem índice.  O LINK coloca as funções na ordem especificada dentro de cada seção na imagem.  
  
 Especificar a ordem em *nome do arquivo*, que é um arquivo de texto \(arquivo de resposta\) que lista o COMDATs na ordem que você deseja vincular o.  Cada linha *no nome do arquivo* contém o nome de um COMDAT.  Um objeto contém COMDATs se foi criado com a opção do \/Gy.  Os nomes de função diferenciam maiúsculas de minúsculas.  
  
 O LINK decoraram formas de identificadores.  O compilador decora um identificador quando cria o arquivo de .obj.  Use a ferramenta de [DUMPBIN](../../build/reference/dumpbin-reference.md) para obter o formulário decorado de um identificador do quando precisar de especifique ao vinculador.  Para obter mais informações sobre nomes decorados, consulte [Nomes decorados](../Topic/Decorated%20Names.md).  
  
 Se mais de uma especificação de \/ORDER é usada, a última especificada entrará em vigor.  
  
 Ordenação permite otimiza o comportamento de paginação do programa com a troca que ajusta\-se agrupando uma função com funções que chama.  Você também pode agrupar funções frequentemente denominados juntos.  Essas técnicas aumenta a probabilidade de uma função chamada estiver na memória quando necessário e não precisará ser paginada de disco.  
  
 O vinculador precede um sublinhado \(\_\) a cada nome decorado *no nome de arquivo* a menos que o nome com um ponto de interrogação \(?\) ou o sinal de arroba \(@\).  Por exemplo, se um arquivo de objeto contém `extern "C" int func(int)` e `int main(void)`, o DUMPBIN [\/SYMBOLS](../../build/reference/symbols.md) listará esses nomes decorados:  
  
```  
009 00000000 SECT3  notype ()    External     | _func  
00A 00000008 SECT3  notype ()    External     | _main  
```  
  
 Porém, o nome especificado no arquivo de pedido deve ser `func` e `main`.  
  
 A opção \/ORDER desabilita vincular incremental.  
  
> [!NOTE]
>  O LINK não pode classificar funções estáticas como os nomes de função estáticos não são nomes públicos de símbolo.  Quando \/ORDER é especificado, o vinculador que LNK4037 aviso é gerado para cada arquivo de símbolo, em ordem, que é estática ou não encontrado.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Otimização** .  
  
4.  Modifique a propriedade de **Ordem de Função** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.FunctionOrder%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)