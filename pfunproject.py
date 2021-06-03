
def Transcription(dna):
    if len(dna)%3==0:
        print("The input DNA seq is ")
        print()
        print(dna)
        print()
        mrna=""
        for i in dna:
            if i=="A":
                mrna+="U"
            elif i=="T":
                mrna+="A"
            elif i=="C":
                mrna+="G"
            elif i=="G":
                mrna+="C"
        return mrna
    else:
        print("Please enter a valid DNA sequence.")
    
def mrna_seq(sequence):
    mrna_codons=[]
    for i in range(0,len(sequence),3):
        mrna_codons.append(sequence[i:i+3])
    return mrna_codons

def Translation(codons):
    proteins=[]
    for i in codons:
        if i=="GCA" or i=="GCC" or i=="GCG" or i=="GCU":
            proteins.append("Ala")
        if i=="AGA" or i=="AGG" or i=="CGA" or i=="CGC" or i=="CGG" or i=="CGU":
            proteins.append("Arg")
        if i=="AAC" or i=="AAU":
            proteins.append("Asn")
        if i=="GAC" or i =="GAU":
            proteins.append("Asp")
        if i=="UGC" or i=="UGU":
            proteins.append("Cys")
        if i=="GAA" or i=="GAG":
            proteins.append("Glu")
        if i=="CAA" or i=="CAG":
            proteins.append("Gln")
        if i=="GGA" or i=="GGC" or i=="GGG" or i=="GGU":
            proteins.append("Gly")
        if i=="CAC" or i=="CAU":
            proteins.append("His")
        if i=="AUA" or i=="AUC" or i=="AUU":
            proteins.append("Ile")
        if i=="UUA" or i=="UUG" or i=="CUA" or i=="CUC" or i=="CUG" or i=="CUU":
            proteins.append("Leu")
        if i=="AAA" or i=="AAG":
            proteins.append("Lys")
        if i=="AUG":
            proteins.append("Met")
        if i=="UUC" or i=="UUU":
            proteins.append("Phe")
        if i=="CCA" or i=="CCC" or i=="CCG" or i=="CCU":
            proteins.append("Pro")
        if i=="AGC" or i=="AGU" or i=="UCA" or i=="UCC" or i=="UCG" or i=="UCU":
            proteins.append("Ser")
        if i=="ACA" or i=="ACC" or i=="ACG" or i=="ACU":
            proteins.append("Thr")
        if i=="UGG":
            proteins.append("Trp")
        if i =="UAC" or i=="UAU":
            proteins.append("Tyr")
        if i=="GUA" or i=="GUC" or i=="GUG" or i=="GUU":
            proteins.append("Val")
    return proteins
    
def protein_seq(aminoacids):
    return(aminoacids)
    
def table(mrna,protein):
    merge=tuple(zip(mrna,protein))
    column_length=[]
    element_tup=2
    for i in range(element_tup):
        column_length.append(max(len(j[i])+2 for j in merge))
    for j in merge:
        for i in range(element_tup):
            print(j[i].ljust(column_length[i]),end=" ")
        print()

def proteinseq(a):
    s=""
    for i in a:
        s+="->"+i
    return s
        
    
    
    
sequence=Transcription("TTAGTGGGCAGAGTTGAGTACACAAGTAAC")
codons=mrna_seq(sequence)
aminoacids=Translation(codons)
a=aminoacids
print("The corresponding mRNA sequence is: ")
print()
print(mrna_seq(sequence))
print()
mrna=mrna_seq(sequence)
protein=protein_seq(aminoacids)
print()
print("In table form:")
print("--------------")
print("mRNA  Protein")
print("--------------")
table(mrna,protein)
print("The protein sequence is:")
print()
print(proteinseq(a))