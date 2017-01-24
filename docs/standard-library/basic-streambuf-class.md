---
title: "Classe basic_streambuf | Microsoft Docs"
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
  - "basic_streambuf"
  - "streambuf/std::basic_streambuf"
  - "std.basic_streambuf"
  - "std::basic_streambuf"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe basic_streambuf"
ms.assetid: 136af6c3-13bf-4501-9288-b93da26efac7
caps.latest.revision: 27
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe basic_streambuf
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve uma classe base abstrata para derivar um buffer de fluxo, que controla a transmissão de elementos em uma representação específica de um fluxo.  
  
## Sintaxe  
  
```  
template<class Elem, class Tr = char_traits<Elem> >  
   class basic_streambuf;  
```  
  
#### Parâmetros  
 `Elem`  
 A[char\_type](../Topic/basic_streambuf::char_type.md).  
  
 `Tr`  
 O caractere[traits\_type](../Topic/basic_streambuf::traits_type.md).  
  
## Comentários  
 A classe de modelo descreve uma classe base abstrata para derivar um buffer de fluxo, que controla a transmissão de elementos em uma representação específica de um fluxo.  Um objeto da classe`basic_streambuf`Ajuda a controlar um fluxo com elementos do tipo`Tr`também conhecido como[char\_type](../Topic/basic_streambuf::char_type.md)cujas características de caractere são determinadas pela classe[char\_traits](../standard-library/char-traits-struct.md)também conhecido como[traits\_type](../Topic/basic_streambuf::traits_type.md).  
  
 Todos os buffers de fluxo controles conceitualmente dois fluxos independentes: um para extrações \(entrada\) e outro para inserções \(saída\).  Uma representação específica pode, no entanto, tornar um ou ambos esses fluxos inacessíveis.  Normalmente, ele mantém alguma relação entre os dois fluxos.  O que você inserir no fluxo de saída de um[basic\_stringbuf](../Topic/basic_stringbuf%20Class.md)\<`Elem``Tr`\> objeto, por exemplo, é o que mais tarde extrair de seu fluxo de entrada.  Quando você posicionar um fluxo de um[basic\_filebuf](../standard-library/basic-filebuf-class.md)\<`Elem``Tr`\> objeto, posicione o outro fluxo em tandem.  
  
 A interface pública à classe de modelo`basic_streambuf`fornece as operações que são comuns a todos os buffers de fluxo, porém especializados.  A interface protegida fornece as operações necessárias para uma representação específica de um fluxo para fazer seu trabalho.  As funções de membro virtual protegida lhe permitem personalizar o comportamento de um buffer de fluxo derivada de uma representação específica de um fluxo.  Cada buffer de fluxo derivada nesta biblioteca descreve como sua especialidade é o comportamento de suas funções de membro virtual protegida.  O comportamento padrão para a classe base, que costuma fazer nada, é descrito neste tópico.  
  
 O restante protegido controle de funções de membro copiar para e de qualquer armazenamento fornecido para as transmissões de buffer para e de fluxos.  Um buffer de entrada, por exemplo, é caracterizado por:  
  
-   [eback](../Topic/basic_streambuf::eback.md)um ponteiro para o início do buffer.  
  
-   [gptr](../Topic/basic_streambuf::gptr.md)um ponteiro para o próximo elemento a ser lido.  
  
-   [egptr](../Topic/basic_streambuf::egptr.md)um ponteiro apenas após o fim do buffer.  
  
 Da mesma forma, um buffer de saída é caracterizado por:  
  
-   [pbase](../Topic/basic_streambuf::pbase.md)um ponteiro para o início do buffer.  
  
-   [pptr](../Topic/basic_streambuf::pptr.md)um ponteiro para o próximo elemento escrever.  
  
-   [epptr](../Topic/basic_streambuf::epptr.md)um ponteiro apenas após o fim do buffer.  
  
 Para qualquer buffer, o seguinte protocolo é usado:  
  
-   Se o próximo ponteiro for null, nenhum buffer existe.  Caso contrário, todos os ponteiros de três ponto a mesma sequência.  Eles podem ser comparados com segurança de pedido.  
  
-   Para um buffer de saída, se o ponteiro seguinte compara menor que o ponteiro final, você pode armazenar um elemento na posição de gravação designado pelo próximo ponteiro.  
  
-   Para um buffer de entrada, se o ponteiro seguinte compara menor que o ponteiro final, você pode ler um elemento na posição de leitura designado pelo próximo ponteiro.  
  
-   Para um buffer de entrada, se o ponteiro de início compara menor que o próximo ponteiro, você pode colocar novamente um elemento na posição putback designada pelo próximo ponteiro decrementado.  
  
 Qualquer protegido funções de membro virtual escrever para uma classe derivada de`basic_streambuf`\<`Elem``Tr`\> deverá cooperar manter esse protocolo.  
  
 Um objeto da classe`basic_streambuf`\<`Elem``Tr`\> armazena os ponteiros de seis descritos anteriormente.  Ele também armazena um objeto de localidade em um objeto do tipo[localidade](../standard-library/locale-class.md)para uso potencial por um buffer de fluxo derivada.  
  
### Construtores  
  
|||  
|-|-|  
|[basic\_streambuf](../Topic/basic_streambuf::basic_streambuf.md)|Constrói um objeto do tipo`basic_streambuf`.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[char\_type](../Topic/basic_streambuf::char_type.md)|Associa um nome de tipo com o`Elem`parâmetro do modelo.|  
|[int\_type](../Topic/basic_streambuf::int_type.md)|Associa um nome de tipo em`basic_streambuf`escopo com o`Elem`parâmetro do modelo.|  
|[off\_type](../Topic/basic_streambuf::off_type.md)|Associa um nome de tipo em`basic_streambuf`escopo com o`Elem`parâmetro do modelo.|  
|[pos\_type](../Topic/basic_streambuf::pos_type.md)|Associa um nome de tipo em`basic_streambuf`escopo com o`Elem`parâmetro do modelo.|  
|[traits\_type](../Topic/basic_streambuf::traits_type.md)|Associa um nome de tipo com o`Tr`parâmetro do modelo.|  
  
### Funções membro  
  
|||  
|-|-|  
|[eback](../Topic/basic_streambuf::eback.md)|Uma função protegida que retorna um ponteiro para o início do buffer de entrada.|  
|[egptr](../Topic/basic_streambuf::egptr.md)|Uma função protegida que retorna um ponteiro apenas após o fim do buffer de entrada.|  
|[epptr](../Topic/basic_streambuf::epptr.md)|Uma função protegida que retorna um ponteiro apenas após o fim do buffer de saída.|  
|[gbump](../Topic/basic_streambuf::gbump.md)|Uma função protegida que adiciona`_Count`para o próximo ponteiro para o buffer de entrada.|  
|[getloc](../Topic/basic_streambuf::getloc.md)|Obtém o`basic_streambuf`localidade do objeto.|  
|[gptr](../Topic/basic_streambuf::gptr.md)|Uma função protegida que retorna um ponteiro para o próximo elemento do buffer de entrada.|  
|[imbue](../Topic/basic_streambuf::imbue.md)|Uma é protegida, função virtual chamada[pubimbue](../Topic/basic_streambuf::pubimbue.md).|  
|[in\_avail](../Topic/basic_streambuf::in_avail.md)|Retorna o número de elementos que estão prontos para ser lido do buffer.|  
|[estouro](../Topic/basic_streambuf::overflow.md)|Uma função virtual protegida que pode ser chamada quando um novo caractere é inserido em um buffer cheio.|  
|[pbackfail](../Topic/basic_streambuf::pbackfail.md)|Uma função de membro virtual protegida que tenta colocar um elemento em novamente o fluxo de entrada, faça\-o elemento atual \(apontado pelo próximo ponteiro\).|  
|[pbase](../Topic/basic_streambuf::pbase.md)|Uma função protegida que retorna um ponteiro para o início do buffer de saída.|  
|[pbump](../Topic/basic_streambuf::pbump.md)|Uma função protegida que adiciona`count`para o próximo ponteiro para o buffer de saída.|  
|[pptr](../Topic/basic_streambuf::pptr.md)|Uma função protegida que retorna um ponteiro para o próximo elemento do buffer de saída.|  
|[pubimbue](../Topic/basic_streambuf::pubimbue.md)|Conjuntos de`basic_streambuf`localidade do objeto.|  
|[pubseekoff](../Topic/basic_streambuf::pubseekoff.md)|Chamadas[seekoff](../Topic/basic_streambuf::seekoff.md)uma função virtual que é substituída em uma classe derivada protegida.|  
|[pubseekpos](../Topic/basic_streambuf::pubseekpos.md)|Chamadas[seekpos](../Topic/basic_streambuf::seekpos.md)uma função virtual que é substituída em uma classe derivada e redefine a posição atual do ponteiro protegida.|  
|[pubsetbuf](../Topic/basic_streambuf::pubsetbuf.md)|Chamadas[setbuf](../Topic/basic_streambuf::setbuf.md)uma função virtual que é substituída em uma classe derivada protegida.|  
|[pubsync](../Topic/basic_streambuf::pubsync.md)|Chamadas[sincronização](../Topic/basic_streambuf::sync.md)uma função virtual que é substituída em uma classe derivada e atualiza o fluxo externo associado a esse buffer protegida.|  
|[sbumpc](../Topic/basic_streambuf::sbumpc.md)|Lê e retorna o elemento atual, mova o ponteiro de fluxo.|  
|[seekoff](../Topic/basic_streambuf::seekoff.md)|A função de membro virtual protegida tenta alterar as posições atuais para os fluxos controlados.|  
|[seekpos](../Topic/basic_streambuf::seekpos.md)|A função de membro virtual protegida tenta alterar as posições atuais para os fluxos controlados.|  
|[setbuf](../Topic/basic_streambuf::setbuf.md)|A função de membro virtual protegida executa uma operação específica de cada buffer de fluxo derivada.|  
|[setg](../Topic/basic_streambuf::setg.md)|Uma função protegida que armazena`_Gbeg`o ponteiro de início, em`_Gnext`no próximo ponteiro, e`_Gend`no ponteiro final para o buffer de entrada.|  
|[setp](../Topic/basic_streambuf::setp.md)|Uma função protegida que armazena`_Pbeg`no ponteiro de início e`_Pend`no ponteiro para o buffer de saída final.|  
|[sgetc](../Topic/basic_streambuf::sgetc.md)|Retorna o elemento atual sem alterar a posição no fluxo.|  
|[sgetn](../Topic/basic_streambuf::sgetn.md)|Retorna o número de elementos de leitura.|  
|[showmanyc](../Topic/basic_streambuf::showmanyc.md)|Função de membro virtual protegida que retorna uma contagem do número de caracteres que pode ser extraído do fluxo de entrada e certifique\-se de que o programa não estará sujeito a uma espera indefinida.|  
|[snextc](../Topic/basic_streambuf::snextc.md)|Lê o elemento atual e retorna o elemento a seguir.|  
|[sputbackc](../Topic/basic_streambuf::sputbackc.md)|Coloca um`char_type`no fluxo.|  
|[sputc](../Topic/basic_streambuf::sputc.md)|Coloca um caractere no fluxo.|  
|[sputn](../Topic/basic_streambuf::sputn.md)|Coloca uma cadeia de caracteres no fluxo.|  
|[stossc](../Topic/basic_streambuf::stossc.md)|Passar o elemento atual no fluxo.|  
|[sungetc](../Topic/basic_streambuf::sungetc.md)|Obtém um caractere do fluxo.|  
|[swap](../Topic/basic_streambuf::swap.md)|Troca os valores nesse objeto para os valores fornecidos`basic_streambuf`parâmetro do objeto.|  
|[sincronização](../Topic/basic_streambuf::sync.md)|Uma função virtual protegida que tenta sincronizar os fluxos controlados com quaisquer fluxos externos associados.|  
|[uflow](../Topic/basic_streambuf::uflow.md)|Uma função virtual protegida que extrai o elemento atual do fluxo de entrada.|  
|[estouro negativo](../Topic/basic_streambuf::underflow.md)|Uma função virtual protegida que extrai o elemento atual do fluxo de entrada.|  
|[xsgetn](../Topic/basic_streambuf::xsgetn.md)|Uma função virtual protegida que extrai elementos de fluxo de entrada.|  
|[xsputn](../Topic/basic_streambuf::xsputn.md)|Uma função virtual protegida que insere elementos no fluxo de saída.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\=](../Topic/basic_streambuf::operator=.md)|Atribui os valores deste objeto de outro`basic_streambuf`objeto.|  
  
## Requisitos  
 **Cabeçalho:**\< streambuf \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)