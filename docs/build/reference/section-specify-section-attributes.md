---
title: "/SECTION (especificar atributos de se&#231;&#227;o) | Microsoft Docs"
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
  - "/section"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /SECTION"
  - "atributos de seção"
  - "opção de vinculador SECTION"
  - "opção de vinculador -SECTION"
ms.assetid: 92b69d81-e421-462e-b46f-7d0dff9b9d16
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /SECTION (especificar atributos de se&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/SECTION:name,[[!]{DEKPRSW}][,ALIGN=#]  
```  
  
## Comentários  
 A opção \/SECTION altera os atributos de uma seção, substituindo os atributos definidos quando o arquivo de .obj da seção foi compilado.  
  
 Uma seção em um arquivo executável portátil de \(PE\) é aproximadamente equivalente a um segmento ou recursos no novo arquivo executável \(NE\).  As seções a seguir contêm código ou os dados.  Diferentemente dos segmentos, as seções são blocos de memória contígua sem restrições de tamanho.  Algumas seções a seguir contêm código ou os dados que seu programa declarados e usa diretamente, enquanto outras seções dos dados sejam criadas para você pelo gerenciador de biblioteca do vinculador e lib.exe \(\) e contêm informações vitais o sistema operacional.  Para obter mais informações sobre os arquivos de NE, consulte o artigo da Base de Dados de Conhecimento “formato de cabeçalho arquivo executável” \(Q65122\).  Você pode localizar artigos da Base de Dados de Conhecimento na Biblioteca MSDN, ou em [http:\/\/support.microsoft.com](http://support.microsoft.com).  
  
 Especificar dois\-pontos \(:\) e *um nome*de seção.  *O nome* é com diferenciação de maiúsculas e minúsculas.  
  
 Não use os seguintes nomes, porque estarão em conflito com nomes padrão.  Por exemplo, .sdata é usado em plataformas de RISC:  
  
-   .arch  
  
-   .bss  
  
-   .data  
  
-   .edata  
  
-   .idata  
  
-   .pdata  
  
-   .rdata  
  
-   .reloc  
  
-   .rsrc  
  
-   .sbss  
  
-   .sdata  
  
-   .srdata  
  
-   .text  
  
-   .xdata  
  
 Especifique um ou mais atributos para a seção.  Os caracteres de atributo, listados abaixo, não diferenciam maiúsculas de minúsculas.  Você deve especificar todos os atributos desejados a seção para ter; causas omitidas de um caractere de atributo que atribuem o operador bit a ser desativado.  Se você não especificar R, W, ou E, a existência leitura, gravação, ou o status executável permanecem inalterados.  
  
 Para negar um atributo, antecedeu o caractere com um ponto de exclamação \(\!\).  Os significados dos caracteres de atributo são mostrados abaixo.  
  
|Caractere|Atributo|Significado|  
|---------------|--------------|-----------------|  
|E|Executar|A seção é executável|  
|R|Ler|Permite operações de leitura em dados|  
|W|Write|Permite operações de gravação de dados|  
|S|Compartilhado|Compartilha a seção entre todos os processos que carregam a imagem|  
|D|Discardable|Marca a seção como discardable|  
|K|Cacheable|Marca a seção como não cacheable|  
|P|Paginável|Marca a seção como não paginável|  
  
 K e P peculiares que os sinalizadores da seção que eles correspondem estão no sentido negativo.  Se você especificar um deless na seção de .text \(\/SECTION: .text, K\), não será diferenças nos sinalizadores da seção quando você executa [DUMPBIN](../../build/reference/dumpbin-options.md) com a opção de [\/HEADERS](../../build/reference/headers.md) ; já foi armazenado em cachê implicitamente.  Para remover a opção, especifique \/SECTION: .text\! K e o DUMPBIN revelarão características da seção, incluir “não armazenado em cachê”.  
  
 Uma seção no arquivo de PE que não tem E, em R, ou em W definido provavelmente é inválido.  
  
 *O \=\#* ALINHAR permite especificar um valor de alinhamento para uma seção específica.  Consulte [\/ALIGN](../../build/reference/align-section-alignment.md) para obter mais informações.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção na caixa de **Opções Adicionais** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)